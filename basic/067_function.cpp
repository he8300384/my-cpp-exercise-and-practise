#include<functional>
#include<iostream>
/*
The std::function is a general-purpose polymorphic function wrapper. It's part of the C++ Standard Library. 
Instances of std::function can store, copy, and invoke any Callable target -- functions,lambda expressions, bind expressions, 
or other function objects, as well as pointers to member functions and pointers to data members.
*/

using namespace std;

struct B
{
    void operator()(int b, const string& message)
    {
    cout << b <<" "<<  message << endl;
    }
    static void show1(int b, const string& message)
    {
    cout << b <<" "<<  message << endl;
    }
    void show(int b, const string& message)
    {
    cout << b <<" "<<  message << endl;
    }
};



using F = void(int, const string&); //函数类型 别名

F show; //用别名声明普通函数

static int a = 20;//仅仅此代码文本访问的全局变量

int main(){
    //1 普通函数包装   
    void(*f1)(int, const string&) = show;//指针写法 效果一样
     
    function<void(int, const string&)> fn1  = show;
    function<F> fnn1  = show;                     //可以填函数别名（可读性不高）
    fn1(1 , "包装器包装普通函数后调用");

    //2 类的静态成员函数 
    function<void(int, const string&)> fn2  = B::show1;
    fn2(2 , "包装器包装静态成员函数后调用");

    //3 仿函数
    B b;
    function<void(int, const string&)> fn3  = B(); 
    fn3(3 , "包装器包装仿函数后调用");
    
    //4 lambda 函数
    auto la = [](int b, const string& message){cout << b <<" "<<  message << endl;};
    function<void(int, const string&)> fn4 = la;
    fn4(4 , "包装器包装lambda函数后调用");

    //5 类的非静态成员函数
    B b1;
    function<void(B&, int, const string&)> fn5  =&B::show ;//注意 类的引用 和 对象传递
    fn5(b1, 5 , "包装器包装普通成员函数后调用");
    
    //6 可以被转换为函数指针的类
    B b2;
    function<void(int, const string&)> fn6  =b2 ;//注意 类的引用 和 对象传递
    fn6(6 , "包装器包装可以被转换为函数指针的类");
    
}

//定义普通函数
void show(int b, const string& message){
    cout << b <<" "<<  message << endl;
}