#include<iostream>

// 编译器能够确定的常量 constexpr  简单说const其实是readonly，constexpr才是const。
//constexpr表示 提示这玩意儿在编译期就可以算出来（前提是为了算出它所依赖的东西也是在编译期可以算出来的）。
//而const只保证了运行时不直接被修改（但这个东西仍然可能是个动态变量）。

int constexpr getNumber()
{
    return 1;
}

int main()
{
    int a[getNumber()];  //函数获取的值 不用constexpr 修饰

    a[0] = 1;

    std::cout<<a[0]<<std::endl;
}
