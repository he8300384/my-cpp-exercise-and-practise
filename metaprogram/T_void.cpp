#include<iostream>
#include<typeinfo>

//使用模板判断是否是 void 

// A 继承了 基础类型 false_type
template<typename T> 
struct is_void : std::false_type{}; //! 除了以下 4 种请况全部返回假

// 调用 A 继承了 基础类型 true_type
// 如果传入 一下任意参数 都属于void 返回真
// 一下都匹配不了就匹配 A 返回假

template<>
struct  is_void<void> : std::true_type{};

template<>
struct  is_void<void const> : std::true_type{};

template<>
struct  is_void<void volatile> : std::true_type{};

template<>
struct  is_void<void const volatile> : std::true_type{};

// 返回值
template <typename T>
inline constexpr bool is_void_v = is_void<T>::value; //直接取std 类的value


int main()
{
    //判断是否是 void 
    std::cout<< is_void_v<void> << std::endl;
    std::cout<< is_void_v<int> << std::endl;
}