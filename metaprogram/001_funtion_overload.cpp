#include<type_traits> //使用标准 true falsse
#include<iostream>

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

int main()
{
    test<char>();
    test<int, int>();
}


