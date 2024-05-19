#include<iostream>
#include<typeinfo>

//我现在有两个函数重载 判断是哪个重载

//! 2222 编译器查找函数定义 此时根据传入值 切换逻辑分支
std::true_type  is_nullptr(std::nullptr_t); //A 参数是 null ptr
std::false_type is_nullptr(...);            //B 参数是 任何东西

//! 1111 编译器试图 使用is_nullptr（） 函数 以推断 返回值类型
template<typename T>
using is_null_pointer_func = decltype(is_nullptr(std::declval<T>()));

int main()
{

    std::cout<< is_null_pointer_func<int>::value << std::endl;
    std::cout<< is_null_pointer_func<std::nullptr_t>::value << std::endl;
}
 
 
 





 
 
 
 
 
 