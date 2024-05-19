#include<iostream>
#include<type_traits>
#include<typeinfo>
//! 特化 偏特化 
//等同于 编译器if语句 处理某种类型 调用不同逻辑
//写法 模板在类名后加 <> 声明特化部分 可以全部参数 可以部分参数特化

//111 我有一些模板类
template<typename T>
struct Myint   {static constexpr const char* name  = "he得自定义类";  T value = 1;};

template<typename T>
struct floatName {static constexpr const char* name  = "is float"; T value = 1.1;};


//222 我定义一个操作让其 支持一般类型  在特化支持以上2模板 
template<typename T>
struct putName
{
    using type = T;
    static void out(){std::cout<<  "泛化默认版本 操作 " << std::endl;}
};

//333 Myint 类得特殊支持
template<typename T>    
struct putName<Myint<T>>
{
    using type = T;
    static void out(){std::cout<<  Myint<T>::name << " 操作" << std::endl;}
};

//444 int 类点的特殊支持        
template<> //唯一参数 int 特化了 <> 写成空的
struct putName<int>
{
    static void out(){std::cout<<   "特化int类型  操作" << std::endl;}
};



int main()
{
    putName<float>::out();
    putName<Myint<int>>::out();
    putName<int>::out();
    
}