#include <vector>
#include <iostream>
#include <string>
 
#include <cstddef>

 

struct TypeDescriptor {
    const char* name;
    size_t size;

    TypeDescriptor(const char* name, size_t size) : name{name}, size{size} {}
    virtual ~TypeDescriptor() {}
    virtual std::string getFullName() const { return name; }
    virtual void dump(const void* obj, int indentLevel = 0) const = 0;
};


// Declare the function template that handles primitive types such as int, std::string, etc.:
template <typename T>
TypeDescriptor* getPrimitiveDescriptor();

// A helper class to find TypeDescriptors in different ways:
struct DefaultResolver {
    

    // This version is called if T has a static member variable named "Reflection":
    template <typename T, /* SFINAE stuff here */>
    static TypeDescriptor* get() {
        return &T::Reflection;
    }

    // This version is called otherwise:
    template <typename T, /* SFINAE stuff here */>
    static TypeDescriptor* get() {
        return getPrimitiveDescriptor<T>();
    }
};

// This is the primary class template for finding all TypeDescriptors:
template <typename T>
struct TypeResolver {
    static TypeDescriptor* get() {
        return DefaultResolver::get<T>();
    }
};


struct Node {
    std::string key;
    int value;
    std::vector<Node> children;
    
    //111111111 宏加塞的 属性信息列表  用一下函数填写
    static  TypeDescriptor_Struct Reflection;

    //111111111 宏加塞的 初始化静态函数 先于main函数注册填写属性信息  填写以上属性列表
    static void initReflection(TypeDescriptor_Struct*);
};

//2222222222222 定义属性信息列表  它是一个 TypeDescriptor_Struct
TypeDescriptor_Struct Node::Reflection{Node::initReflection};

//2222222222222 定义加塞的进类的函数 使用宏动态针对每个类声明
void Node::initReflection( TypeDescriptor_Struct* typeDesc) {

    //! 关键statice函数先于main函数 宏替换关键字为Node 以填充 decltype< >
    //  T 这里被替换为node  它实际是多种可能性的
    using T = Node;             

    typeDesc->name = "Node";

    //宏要替换为sizeof(Node)  
    typeDesc->size = sizeof(T); 

    //33333333333  一系列 成员参数搜集 
    //TypeResolver 是一个模板类 get（）方法 返回成员指针 或者 基础类型指针
    typeDesc->members = {
        {"key", offsetof(T, key), TypeResolver<decltype(T::key)>::get()},
        {"value", offsetof(T, value),  TypeResolver<decltype(T::value)>::get()},
        {"children", offsetof(T, children),  TypeResolver<decltype(T::children)>::get()},
    };
}

int main()
{

}