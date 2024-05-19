#include<iostream>
#include<typeinfo>

//判断 是否是数组

template<typename T>
struct is_array :std::false_type{};


template<typename T, std::size_t N>  
struct is_array<T[N]> : std::true_type {};
 
template<typename T>  
struct is_array<T[]> : std::true_type {};





 
 
 
 
 
 