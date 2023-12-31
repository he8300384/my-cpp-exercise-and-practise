#include<iostream>

// c++ 不允许switch 使用 字符串
int main()
{
    int a =2;

    switch (  a  )
    {
    case 1:
        std::cout<<"aaaaa\n";
        break;
    case 2:
        std::cout<<"bbbbb\n";
        break;
    default:
        break;
    }
}
