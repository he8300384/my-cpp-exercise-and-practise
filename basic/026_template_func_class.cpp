#include<iostream>
#include<string.h>

using namespace std;

//演示了模板的灵活度
void func()
{
    cout<< "调用了普通函数\n";
}

class classFunc
{
public:
    void operator ()()
    {
        cout<< "调用了类的仿函数\n";
    }
};

template<typename T>
void funs(T a)
{
    a();
}

int main()
{
    classFunc c;
    funs(func); //既可以传函数
    funs(c);    //也可以传类
    
}