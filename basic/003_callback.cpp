#include<iostream>
#include<string.h>

using namespace std;

void  callA(int a)
{
    cout<< "调用函数A输出: " << a << "\n";
}

void  callB(int a)
{
    cout<< "调用函数A输出: " << a << "\n";
}

//注意函数指针写法C void(*calls)(int) C++ void(calls)(int)  
void  callback(void(*calls)(int),int a) 
{
    cout<<"回调前工作\n";
    calls(a);
    cout<<"回调后工作\n\n";
}

int main()
{
    callback(callB, 6);
    callback(callA, 3);
}     