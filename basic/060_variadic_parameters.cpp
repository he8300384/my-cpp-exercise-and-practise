#include<iostream>
#include<string>
using namespace std;


//可变参数函数 要写一个普通函数 和一个模板函数实现可变参数
 void print1()
 {
    cout<< "print1终止递归\n"; 
 }

 template <typename T, typename ...Args>  //固定写法  ...代表可变参数
 void print1(T a, Args... arg)
 {
    cout<< "参数: " << a << " " << " 剩余参数" << sizeof...(arg) << "\n";   //sizeof...(arg) 写法奇怪 用于看参数剩余
    print1(arg...); //递归调用  
 }

 //固定参数 可变参数混用 利用普通模板嵌套递归模板
template <typename ...Args>  //固定写法  ...代表可变参数
 void print2(const string& str, Args... arg)
 {
    cout<< str << endl;
    print1(arg...); //递归调用 
    cout<< "print2终止\n"; 
 }


int main( ){
  print1(1 , 3, "a",4);
  print2("固定参数 可变参数混用", 1,3,"11");
}