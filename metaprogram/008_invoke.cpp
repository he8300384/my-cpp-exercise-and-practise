#include<functional>
#include<iostream>

int add(int i){ return i + 1; }

struct S
{
    int j = 3;
    int add(int i){ return i + j; }
};


int main()
{
    //1111 可以调用普通函数
    std::cout<<std::invoke(&add, 3) <<"\n";

    //2222  主要用于成员函数调用 原来写法需要很多行
    S s;
    auto fp = &S::add;
    std::cout<<(s.*fp)(2)<<"\n";

    std::cout << std::invoke(&S::add, s, 10) << "\n";   //书写更舒服 实例 s 自动识别
    std::cout << std::invoke(&S::j, s)       << "\n";   //连成员函数都能直接访问

    //333333  可直接原地调用lamdba表达式
    std::invoke([](){std::cout<<"立即调用";}); //不用invoke 是没法立即调用的
}

