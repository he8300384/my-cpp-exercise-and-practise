#include<type_traits> //使用标准 true falsse
#include<iostream>

//检测类作用域是否包含类型  用上一个文件列子识别成员 运用模板生成判定函数 
#define HAS_TYPE(MemType)                                           \
    template<typename, typename = std::void_t<>>                    \
    struct HasType_##MemType : std::false_type{};                   \
    template<typename T>                                            \
    struct HasType_##MemType<T, std::void_t<typename T::MemType>>   \
    : std::true_type{};                                             
    
   
//检测类成员是否存在  通过调用成员让后 推导成员类型 再构造void_t  //! 构造结果不重要  构造失败就会说明没有成员 然后转向 构造出false_type
 
#define HAS_MEMBER(Member)                                          \
template<typename, typename = std::void_t<>>                        \
struct HasMember_##Member : std::false_type { };                    \
template<typename T>                                                \
struct HasMember_##Member<T, std::void_t<decltype(&T::Member)>>     \
: std::true_type {};


HAS_TYPE(AA) 

HAS_MEMBER(size)
HAS_MEMBER(name)
 

struct MyclassA{using AA= int;};
struct MyclassB
{
private: 
    std::string name;
public:
    int size;   
};


int main()
{
    //类型是否有
    std::cout<< HasType_AA<int>::value      <<std::endl;    //int 明显没有包含AA类型
    std::cout<< HasType_AA<MyclassA>::value  <<std::endl;    //自定义类有 AA类型
    std::cout<< HasType_AA<MyclassB>::value  <<std::endl;    //自定义类无 AA类型

    //共有成员是否有
    std::cout<< HasMember_size<MyclassB>::value  <<std::endl;    //尝试调用成员就能做出判断了 成员类型并无影响
    //std::cout<< HasMember_name<MyclassB>::value  <<std::endl;    //! 错误私有类型 无法调用
}

