#include<iostream>
#include<string.h>

using namespace std;

//演示了模板的灵活度
 
template<class T>
class classFunc
{
    
    T a;
public:
    friend void out(classFunc<int> &c);//模板类外友元

    friend void out2(classFunc<T> &c)//模板类内友元
    {
        cout << "使用类内友元函数调用类函数\n";
        c.show();
    }
    void show() {cout<< "调用了类的函数显示参数a=" << a <<"\n" ;}
};

 void out(classFunc<int> &c)
 {
    cout << "使用友元函数调用类函数\n";
    c.show();
 }

int main()
{   
    classFunc<int> a;
    out(a);
    out2(a);
}
    