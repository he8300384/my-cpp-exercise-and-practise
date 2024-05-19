#include<iostream>

//1111 A的类型参数  是  T
template <typename T>
struct A{ using type =  T; };


//1.1      B的类型参数 什么情况都是  int 
//! 前提是编译要通过 这种写法是为了模板参数 特定情况故意编译失败 从而丢弃类定义 以达到if else的效果
template <typename >
struct B{ using type =  int; };

//22222   非类型 要求一个具体类新
template<int>
void out1(){std::cout << "int 版本" <<std::endl;}
template<char>
void out2(){std::cout << "char 版本" <<std::endl;}

//33333 套娃
//先准备两个模板
template<typename  T1, typename T2>
struct test1{};

template<typename >
struct test2{};

//以下模板函数使用上面俩个模板作为参数 注意class 关键词
template<template<typename, typename> class  s>
void outss(){std::cout << "参数中传入 有两个参数的模板" <<std::endl;}

template<template<typename>  class  s>
void outss(){std::cout << "参数中传入 有一个参数的模板" <<std::endl;}

//44444 参数包批发
template<typename...>
void outany(){std::cout << "不关心参数数量" <<std::endl;}

template<typename... as>
void outArgsNum(as... args)
{
    std::cout<<sizeof...(args)<<std::endl;
}

int main()
{
    //返回填写的类型
    A<int>::type a = 1;

    //用什么东西往模板填都无所谓
    B<char>::type b = 2.2;
    B<A<int>>::type c = 2.2;

    //这里只关心值类型 值不重要
    out1< 1 >(); 
    out2<'a'>();
    outss<test1>();
    outss<test2>();

    //...确保参数数量无关化
    outany<int>();
    outany<int, float>();
    outany<int, float, char ,char ,char ,char ,char ,char ,char ,char >();
    outArgsNum(1,2,3);
    outArgsNum(1,2,3,2,'a');
}