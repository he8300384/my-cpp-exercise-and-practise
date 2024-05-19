#include<iostream>
#include<typeinfo>

//! _t 表示获取值类型
template<typename T>
struct TypeIdertity
{
    using type = T;
};

template <typename T>
using TypeIdentity_t = typename TypeIdertity<T>::type;


int main()
{
    std::cout<< typeid(TypeIdertity<int>::type).name() << std::endl;

    std::cout<< typeid(TypeIdentity_t<int>).name() << std::endl;  
}