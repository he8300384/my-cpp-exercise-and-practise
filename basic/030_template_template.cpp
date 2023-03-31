#include<iostream>
#include<string.h>

using namespace std;

//演示了模板嵌套
template<class T >
class C1
{
    T ma = 1;
    public:
    void out()
    {
        cout<<"调用嵌套模板类 1 输出: ";
         
        cout<< ma <<" ";
        cout << endl;
    }
};

template<class T >
class C2
{
    T ma = 2;
    public:
    void out()
    {
        cout<<"调用嵌套模板类 2 输出: ";
         
        cout<< ma <<" ";
        cout << endl;
    }
};

 
template< template<class >class T, class T2 > //这样写class T 就是一个嵌套的模板类
class classFunc
{
    T2 a;
public:
    T<T2> my_class;
    
    void show() 
    {   
        my_class.out();
        cout<< "调用了类的函数显示参数" <<"\n" ;
    }
     
 
};
 
 

int main()
{   
    
    classFunc<C1, int> a;//根本无需具实例化C1 直接指定类型生成 实例
    a.show();
    classFunc<C2, int> b;//根本无需具实例化C2 直接指定类型生成 实例
    b.show();
}
    