#include<iostream>

//枚举值可以 随意指定 整数 使得一批数据调用查看方便 qie'xi'z'n'zhi
enum type{
    A = 1,
    B = 2,
    C = 30,
};

int main()
{
    std::cout<<type::A<< std::endl;
}