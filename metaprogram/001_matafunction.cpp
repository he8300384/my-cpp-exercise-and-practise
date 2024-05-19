/*
• Function templates define a family of functions for different template arguments.
• When you pass arguments to function parameters depending on template parameters, function
templates deduce the template parameters to be instantiated for the corresponding parameter types.
• You can explicitly qualify the leading template parameters.
• You can define default arguments for template parameters. These may refer to previous template
parameters and be followed by parameters not having default arguments.
• You can overload function templates.
• When overloading function templates with other function templates, you should ensure that only
one of them matches for any call.
• When you overload function templates, limit your changes to specifying template parameters explicitly.
• Ensure the compiler sees all overloaded versions of function templates before you call them
*/
#include<iostream>

template<typename A>
void AaddB(A a, A b)
{
    std::cout << a + b << std::endl;
}

template<typename A, typename B>
B AaddB(A a, B b)
{   
    std::cout<< a + b << std::endl;
    return a + b;
}

//可以特指定具体类型
template<typename RT = long, typename T1, typename T2>
RT max (T1 a, T2 b)
{
return b < a ? a : b;
}


//std::common_type_t 使得可以自动返回T1 或 T2 不会发生强制转换
//支持auto   auto b = ::max<double,int,long double>(7.2, 4);
#include <type_traits>
template<typename T1, typename T2>
std::common_type_t<T1,T2> max (T1 a, T2 b)
{
return b < a ? a : b;
}

//以上内容 可写为这种形式 还可以包含三元运算符
//std::decay_t 移除const volatile 等修饰符

#include <type_traits>
template<typename T1, typename T2, typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max (T1 a, T2 b)
{
return b < a ? a : b;
}

//可指定 T 默认类型
template<typename T, typename =  int>
void outint(T a)
{
    std::cout<< a << std::endl; 
}


int main()
{
    //两种书写格式
    AaddB<int>(1,2);
    AaddB(1,2);

    std::cout<<AaddB(1.1, 2)<<std::endl; //注意返回值被模板切换回B 这里是int

   //std::cout<<max(2.1, 2)<<std::endl; //注意返回值由于std::common_type_t避免了类型转换
   outint("aa");
   outint( 11 );
}
