#include<type_traits> //使用标准 true falsse
#include<iostream>

template<typename ...> using VoidT = void; //匿名多参数模板 忽略所有个数参数

//作用： 一般情况都为假 
//两参数基础模板  此处参数匿名 表示有两个参数 第二个默认是voidT   
template<typename  , typename  = VoidT<>>  
struct  HasInt : std::false_type {};


//作用： 符合情况才为真     
//偏特化单参数模板 
//! 我们实际总是使用一个参数去调用模板  
//! 所以一开始尝试此处模板推导  HasInt<T, 此处如果voidT构造失败会转向以上代码 >  成功就构造出int类型的 HasInt
//注意 myType 私有的话不能访问 总会构造失败
template<typename T>
struct HasInt<T, VoidT<typename T::myType >> : std::true_type  {}; 

//测试样本
struct Test
{
    using myType = int; //在Test类命名空间中 使用自定义类别
};

template <typename T1, typename T2  >
void test( )
{
    std::cout<<"两个参数版本"<<std::endl;
}

template < typename = char >
void test( )
{
    std::cout<<"int 版本"<<std::endl;
}

struct Mu{};

int main()
{
    std::cout<<HasInt<Test>::value<<std::endl;
    test<char>();
    test<int, int>();
}


