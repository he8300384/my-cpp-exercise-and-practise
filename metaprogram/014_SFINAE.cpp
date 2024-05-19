#include<iostream>
#include<typeinfo>

template<typename T>
std::true_type can_have_pointer_to_member(int T::*);

template<typename T>
std::true_type can_have_pointer_to_member(...);

template<typename T>

using can_have_menber_ptr =  decltype(can_have_pointer_to_member<T>(nullptr)) ; //一旦有decltype 编译器会尝试 寻找括号中 的式子或函数调用

struct  Foo{};
main()
{


//std::cout<<  can_have_pointer_to_member<int>;

}
