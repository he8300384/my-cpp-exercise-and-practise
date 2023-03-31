#include<iostream>
#include<string.h>

using namespace std;

//演示了模板类拥有友元函数是模板类的写法 此种方法有实用价值

template <typename T>                   //1 先声明模板函数
void out(T& a);
 
template<class T1>
class classFunc
{
friend void out<>(classFunc<T1> &c);      //2 模板类作为模板函数参数
    T1 a=0 ;
public:
    void show() 
    {cout<< "调用了类的函数显示参数a=" << a <<"\n" ;}
};

template <typename T>   
 void out(T& a)                       //3 定义模板函数
 {
    cout << "使用通用模板友元函数1 \n";
    a.show();
 }

template<>                              //多来个具化版本
void out(classFunc<int>& a)
{
    cout << "使用具化版友元函数2 \n";
    a.show();
}

int main()
{   
    classFunc<int> a;
    out(a);
    classFunc<double> c;
    out(c);
}
    