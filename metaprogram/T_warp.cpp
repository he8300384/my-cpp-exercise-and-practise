#include<iostream>
#include<typeinfo>

// 将 类型及其值 绑定为一个参数 （柯里化）

//一下例子 将 bool true  等价转化为 “true_type” 注意 true type 不是字符

template<class T, T v>
struct integral_constant  //2222222222222 
{
    static constexpr T value = v; //! 存储类型值

    using value_type =T ; 

    using type = integral_constant<T, v>; //! 存储类型自身

    constexpr operator value_type() const noexcept  // noexcept 不抛出异常
    {
        return value;
    }
    constexpr value_type operator()() const noexcept
    {
        return value;
    }
};

//布尔绑定
template <bool B>
using bool_constant = integral_constant<bool, B>; //11111111 展开为 <bool, bool B> 以使用 
using true_type     = bool_constant<true>; //等于integral_constant<bool, true>    一种柯里化 单参数调用思想
using notTrue_type  = bool_constant<false>;

//int 绑定
template <int C>
using int_constant = integral_constant<int, C>;
using int_one = int_constant<1>;
using int_two = int_constant<2>;


//! 以上用到了 operater 关键字 使得类有函数用法
class MyFunctor {
public:
    int operator()() const {
        return 42;
    }
};
 
    

int main()
{   
    // bool类型不同结果 被绑定到了 自定义关键字
    std::cout<<  true_type::value << std::endl;
    std::cout<<  true_type() << std::endl; //
    std::cout<<  notTrue_type::operator bool << std::endl;
    std::cout<<  notTrue_type::value << std::endl << std::endl;  

    // 两个int 绑定到了 int_one int_two
    std::cout<< int_one()  << std::endl;
    std::cout<< int_two::value  << std::endl << std::endl;  
     

    // operater 关键字 用法
    MyFunctor myFunctor;
    std::cout << myFunctor() << std::endl; // This calls the operator() function
    return 0;
 
}