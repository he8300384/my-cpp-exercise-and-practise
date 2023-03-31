#include<iostream>
#include<string>
#include<functional>
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

//1 普通函数
 void show1() {
   cout << "你好 \n";
 }

 //2 普通单参数函数
 void show2(const char* s) {
   cout << "你好 " << s << " \n";
 }

 //3类的普通成员函数
 struct S
 {
   void show3(int num, const char* s) {
      cout << num << "你好 " << s << " \n";
   }
 };
   
template<typename Fn, typename ...Args>
void show(Fn fn, Args...args) //可以后置定义 ->decltype(bind(fn, args...)) 返回bind对象方便继续使用
{
   cout<< "通用模板准备工作\n";

   auto f=  bind(fn, args...); //bind可以自己展开参数包会处理 args...  
   f();

   cout<< "通用模板完成工作\n\n";
}

//支持完美转发移动语义的版本 
template<typename Fn, typename ...Args>
auto showa(Fn&& fn, Args&&... args) -> decltype(bind(forward<Fn>(fn),forward<Args>(args)...))  
{
   cout<< "通用模板2准备工作\n";

   auto f=  bind(forward<Fn>(fn),forward<Args>(args)...); //bind可以自己展开参数包会处理 args...  
   f();

   cout<< "通用模板2完成工作\n\n";
   return f;
}


int main( ){
   
 show(show1);
 show(show2,"aad");

 S s;
 show(&S::show3,&s, 1, "ssssss");

 auto ss =  showa(&S::show3,&s, 1, "ssssss");
   ss();
}