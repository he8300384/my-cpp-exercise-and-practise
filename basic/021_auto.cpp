#include<iostream>
#include<string.h>

using namespace std;

int func(int a, double b, const char* c)
{
    cout<<"调用了函数\n";
    return 4.4;
}

int main()
{
    auto name = "xfasdf"; 
    cout<<"你输入了"<< name <<"\n";

    auto pf1 = func;//这样写函数指针简单得多
    pf1(1,2.2 ,"adf");
}