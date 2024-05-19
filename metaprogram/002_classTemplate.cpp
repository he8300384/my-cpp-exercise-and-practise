#include<iostream>
#include<string>

//可以传入类型
template<typename A>
struct pepole1
{
    A value ;
};

//可以传 特定类型 值
template<int a>
struct pepole2
{
   static constexpr int value = a; //不加 constexpr 编译是不能通过的
};

//可以传 自动 值 很多值无法自动推断
template<auto a>
struct pepole3
{
   static constexpr auto value = a;  
};

//可以传 指定类型 值
template<typename T, T a>
struct pepole4
{
   static constexpr T value = a;  
};

//可以传 指定类型 值
template<typename T>
struct pepole5
{
    T value ;  
};

//可以具体指定类的 类型 
//这个就是一种类重载了 当实例是<int> 使用以下版本 
template<>
struct pepole5<int>
{ 
    static constexpr int value = 1;
};

//可以取别名
using INTpepole = pepole5<int>;

 

int main()
{
    pepole1<int> p;
    p.value = 1;

    pepole5<std::string> p5; 
    p5.value = "dasf";

    std::cout<< pepole2<2>::value <<std::endl;
    
    std::cout<< pepole3<true>::value <<std::endl;

    std::cout<<  p5.value <<std::endl;

    std::cout<< pepole5<int>::value << std::endl;

    std::cout<< INTpepole::value << std::endl;

    //std::cout<< pepole4<float, 1>::value <<std::endl; //浮点数不能用于推断

}