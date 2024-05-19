#include<iostream>
#include<typeinfo>

//分支判断 恩 很有用

template<typename T>
struct TypeIdertity{using type = T;};

template<bool Condition, typename T, typename F>
struct conditional : TypeIdertity<T> {}; //! 111111  所有情况 返回 T

template<typename T, typename F>         //! 222222  这种情况 返回 F
struct conditional <false, T, F> : TypeIdertity<F> {};



int main()
{
    //一个开关切换类型
     std::cout<< typeid( conditional<false, int, float>::type).name() << std::endl;
     std::cout<< typeid( conditional<true , int, float>::type).name() << std::endl;
}