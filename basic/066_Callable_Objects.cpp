#include<iostream>

using namespace std;

struct B
{
    void operator()(int b, const string& message)
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

int main(){
    show(1 , "普通调用");   //普通调用
    void(*f1)(int, const string&) = show;
    void(&f2)(int, const string&) = show;

    f1(2 , "函数指针调用");
    f2(3 , "引用调用");

    F* f3 =show;
    F& f4 =show;

    f1(4 , "函数指针调用");
    f2(5 , "引用调用");

    B b;
    B& bb = b;
    b(6 , "仿函数调用");
    B()(7 , "匿名对象调用");
    bb(8 , "引用对象调用");


    B bbb;
    bbb.show(9 , "成员函数调用");

    void(B::*ff)(int, const string&) = &B::show;  //定义类成员函数指针
    (bbb.*ff)(10 , "成员函数指针调用");
}

//定义普通函数
void show(int b, const string& message){
    cout << b <<" "<<  message << endl;
}