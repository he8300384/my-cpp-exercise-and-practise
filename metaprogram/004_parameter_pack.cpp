#include<iostream>
#include<typeinfo>

//使用模板判断是否是 void 
template<typename... T> struct A{};

//多参数可能性
using intA = A<int>;
using floatA = A<float>;
using int2A = A<int, int>;
using emptyA = A<>;

//多参数必须在参数列表最后
template<typename T, typename... A > 
struct B
{

    static void out(A... a)
    {
        (std::cout<< ... << a ) <<std::endl;   
    }
};

//多参数可能性
using B1 = B<float, int ,int ,int>;

//可套娃
template<unsigned...> struct Tensor;
template<unsigned... Dims1, unsigned... Dims2>
auto compose(Tensor<Dims1...>, Tensor<Dims2...>);

 
int main()
{
  B1::out(1,2,3);
}