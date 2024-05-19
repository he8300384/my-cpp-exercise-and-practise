#include<iostream>
#include<typeinfo>

//同类型判断

template<typename T1 , typename T2>
struct is_same : std::false_type {};

template<typename T> //这里只有一个T 是ok的 下面参数列表对应就行
struct is_same<T, T> : std::true_type{};
 
template<typename T1, typename T2>
constexpr bool is_same_v =  is_same<T1, T2>::value;




int main()
{
    //一个开关切换类型
     std::cout<<  is_same_v<int, float> << std::endl;
     std::cout<<  is_same_v<int, int  > << std::endl;
}