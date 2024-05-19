#include<iostream>
#include<typeinfo>

//最简单的例子 返回输入值类型 c++20有类似 std::type_identity
template<typename T>
struct TypeIdertity
{
    using type = T;
};

//匹配分支 1 如果传递 随意类型 原封不动返回
template<typename T>
struct  remove_const: TypeIdertity<T> { };
//匹配分支2 如果匹配上 const 还是返回原始类型版本
//注意匹配不是绝对的 编译器会选择近似版本解读 注意后面调用顺序不一致 不同于函数需要精准调用结果
template<typename T>
struct  remove_const<T const>: TypeIdertity<T> { };


template<typename T>
using remove_const_t = typename remove_const<T>::type;



int main()
{
    //去除了 int const 属性 注意模板在顺序不一致情况也解读了 不同于函数
     remove_const_t<const int> a = 10;
     remove_const_t<int const> b = 10;
     const int c = 10;

     a = 20;
     b = 30;
     //c = 40; 编译不会通过

     //通过抹除const 值被成功修改
     std::cout<< a << std::endl; 
     std::cout<< b << std::endl; 
     
}