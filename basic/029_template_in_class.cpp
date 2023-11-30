#include<iostream>
#include<string.h>

using namespace std;

//演示了模板类拥有友元函数是模板类的写法 此种方法有实用价值
 
template<class T1>
class classFunc
{
    T1 a;
public:
    void show() 
    {cout<< "调用了类的函数显示参数a=" << a <<"\n" ;}
    template <typename T>   
        void out(T a)    
        {                  
            cout << "使用类内模板函数显示 :" << a <<"\n";           
        }

    template <typename T>   
        void out2(T a) ;   
           

};

//注意模板类里的模板函数在外定义写法
template<class T1>
template <typename T>
void classFunc<T1>::out2(T a)   
        {                  
            cout << "使用在外定义模板函数显示 :" << a <<"\n";           
        }   

class C2
{
    public:
    template <typename T>
    void out(T a){cout << "普通类里的模板函数显示 ："<< a <<endl;}
};       
 

int main()
{   
    classFunc<int> a;
    a.out(11);
    a.out2(11);

    C2  c;
    c.out("ccc");
    c.out(2);

}
    