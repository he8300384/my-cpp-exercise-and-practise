#include<iostream>
#include<typeinfo>

//最简单的例子 返回输入值类型 c++20有类似 std::type_identity
template<typename T>
struct TypeIdertity
{
    using type = T;
};

//与常规编程习惯有所区别 模板类似函数 但不是函数
template<int x, int y>
struct ADD
{ 
    static constexpr int value = x + y; // constexpr 会使得做编译期计算 
};

//以模板函数样式实现以上功能
template<typename X, typename Y>
constexpr auto sum(X x, Y y)
{
    return x + y;
}


int main()
{
    std::cout<< typeid(TypeIdertity<int>::type).name() << std::endl;
    std::cout<< ADD<1,2>::value << std::endl;
    std::cout<< sum<int, int>(2,4) <<std::endl;
}