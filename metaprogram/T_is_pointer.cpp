#include<iostream>
#include<typeinfo>

//判断 是否是指针

template<typename T>
struct is_pointer_impl :std::false_type{};


template<typename T>  
struct is_pointer_impl<T *> : std::true_type {};
 
template<typename T>  
using is_pointer = is_pointer_impl<remove_cv_t<T>> ; // 注意嵌套了 remove_cv_t 模板 用以去除 const volatile 等修饰符号





 
 
 
 
 
 