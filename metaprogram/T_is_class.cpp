struct test{};

//using memptr = int test::* ; //如果test是一个类 那么这句指针 构造成立 

//using memptr = int long::* ; //基本类型不可能构造 指针 以此区分class 和基本类型 

template<typename T> constexpr bool is_class_or_union(int T::*)
{
    return not std::is_union<T>::value; // is_union<T>要先实现
}

template<typename T> constexpr bool is_class_or_union(...)
{
    return false;
}

template<typename T> 
using is_class = std::bool_constant<is_class_or_union<T>(nullptr)>;
 
 