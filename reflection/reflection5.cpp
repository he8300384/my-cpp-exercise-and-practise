#include <vector>
#include <iostream>
#include <string>
#include <cstddef>

 

//--------------------------------------------------------
// Base class of all type descriptors
//--------------------------------------------------------

//接口 所有操作用到的描述结构体 TypeDescriptor_Struct 继承了它
struct TypeDescriptor {
    const char* name;     //每个东西要个名字
    size_t size;          //大小

    TypeDescriptor(const char* name, size_t size) : name{name}, size{size} {}
    virtual ~TypeDescriptor() {}
    virtual std::string getFullName() const { return name; }
    virtual void dump(const void* obj, int indentLevel = 0) const = 0;
};

//--------------------------------------------------------
// Finding type descriptors
//--------------------------------------------------------

//  原生类型描述支持函数 such as int, std::string, etc.:
template <typename T>
TypeDescriptor* getPrimitiveDescriptor();

// 总之这个难看的类 只是判断一个T 是class 还是 int float string
struct DefaultResolver {
    template <typename T> static char func(decltype(&T::Reflection)); //如果是 func（ 类型是 目标反射类 成员reflection 类型）
    template <typename T> static int func(...);
    //模板类用于判断 T 是否有reflection 成员 好jb 难看的写法 模板元编程可以去死了 还不如用汇编写直白
    template <typename T>
    struct IsReflected 
    {
        enum { value = (sizeof(func<T>(nullptr)) == sizeof(char)) }; // 使用枚举方便调用和检索 判断结果 这里只有一个布尔值 为毛不用模板函数 要用个类
    };
    // This version is called if T has a static member named "Reflection":
    // 通过自己塞到 类中的函数reflection 判断 T 是否是个类
    // std::enable_if 模板元编程   std::enable_if < true > 使得 函数不被特定类调用
    // 目前 通过enable if 使得 get（） 拥有不同版本
    template <typename T, typename std::enable_if<IsReflected<T>::value, int>::type = 0> //能用 但是 难看猥琐的实现
    static TypeDescriptor* get() {
        return &T::Reflection;       //属于类 返回类中自己 插入的reflection 描述结构体
    }

    // 不是类的情况 This version is called otherwise:
    template <typename T, typename std::enable_if<!IsReflected<T>::value, int>::type = 0>
    static TypeDescriptor* get() {
        return getPrimitiveDescriptor<T>();    //属于基本类型 用函数新建一个描述结构体
    }
};

// 用以上代码调用对应的 getPrimitiveDescriptor<T>();
template <typename T>
struct TypeResolver {
    static TypeDescriptor* get() {
        return DefaultResolver::get<T>();
    }
};

//--------------------------------------------------------
// Type descriptors for user-defined structs/classes
//--------------------------------------------------------

struct TypeDescriptor_Struct : TypeDescriptor {
    struct Member 
    {
        const char* name;
        size_t offset;
        TypeDescriptor* type;
    };

    std::vector<Member> members; // 针对class类型 维护了一个成员列表 记录成员的 名字 偏移 和 类型

    //注意函数指针 void (*init)(TypeDescriptor_Struct*) 接受一个init 函数 用来初始化自己
    TypeDescriptor_Struct(void (*init)(TypeDescriptor_Struct*)) : TypeDescriptor{nullptr, 0} 
    {
        init(this);
    }

    TypeDescriptor_Struct(const char* name, size_t size, const std::initializer_list<Member>& initList) : TypeDescriptor{nullptr, 0}, members{initList} 
    {}

    virtual void dump(const void* obj, int indentLevel) const override 
    {
        std::cout << name << " {" << std::endl;
        for (const Member& member : members) 
        {
            std::cout << std::string(4 * (indentLevel + 1), ' ') << member.name << " = ";
            member.type->dump((char*) obj + member.offset, indentLevel + 1);
            std::cout << std::endl;
        }
        std::cout << std::string(4 * indentLevel, ' ') << "}";
    }
};

#define REFLECT() \
    friend struct reflect::DefaultResolver; \
    static reflect::TypeDescriptor_Struct Reflection; \
    static void initReflection(reflect::TypeDescriptor_Struct*);

#define REFLECT_STRUCT_BEGIN(type) \
    reflect::TypeDescriptor_Struct type::Reflection{type::initReflection}; \
    void type::initReflection(reflect::TypeDescriptor_Struct* typeDesc) { \
        using T = type; \
        typeDesc->name = #type; \
        typeDesc->size = sizeof(T); \
        typeDesc->members = {

#define REFLECT_STRUCT_MEMBER(name) \
            {#name, offsetof(T, name), reflect::TypeResolver<decltype(T::name)>::get()},

#define REFLECT_STRUCT_END() \
        }; \
    }

//--------------------------------------------------------
// Type descriptors for std::vector
//--------------------------------------------------------

struct TypeDescriptor_StdVector : TypeDescriptor {
    TypeDescriptor* itemType;
    size_t (*getSize)(const void*);
    const void* (*getItem)(const void*, size_t);

    template <typename ItemType>
    TypeDescriptor_StdVector(ItemType*)
        : TypeDescriptor{"std::vector<>", sizeof(std::vector<ItemType>)},
                         itemType{TypeResolver<ItemType>::get()} {
        getSize = [](const void* vecPtr) -> size_t {
            const std::vector<ItemType>& vec = *(const std::vector<ItemType>*) vecPtr;
            return vec.size();
        };
        getItem = [](const void* vecPtr, size_t index) -> const void* {
            const std::vector<ItemType>& vec = *(const std::vector<ItemType>*) vecPtr;
            return &vec[index];
        };
    }
    virtual std::string getFullName() const override {
        return std::string("std::vector<") + itemType->getFullName() + ">";
    }
    virtual void dump(const void* obj, int indentLevel) const override {
        size_t numItems = getSize(obj);
        std::cout << getFullName();
        if (numItems == 0) {
            std::cout << "{}";
        } else {
            std::cout << "{" << std::endl;
            for (size_t index = 0; index < numItems; index++) {
                std::cout << std::string(4 * (indentLevel + 1), ' ') << "[" << index << "] ";
                itemType->dump(getItem(obj, index), indentLevel + 1);
                std::cout << std::endl;
            }
            std::cout << std::string(4 * indentLevel, ' ') << "}";
        }
    }
};

// Partially specialize TypeResolver<> for std::vectors:
template <typename T>
class TypeResolver<std::vector<T>> {
public:
    static TypeDescriptor* get() {
        static TypeDescriptor_StdVector typeDesc{(T*) nullptr};
        return &typeDesc;
    }
};

 