#include<iostream>
#include<typeinfo>


template<int x >
struct Value
{ 
    static constexpr int value = x ;  
};

template<auto X>
inline constexpr auto  
    value_v = Value<X>::value;


int main()
{
    //值获取
    std::cout<<  Value<12>::value << std::endl;
    //!简化值获取 此类模板命名规则 加 _v
    std::cout<<  value_v<22> <<std::endl;
}