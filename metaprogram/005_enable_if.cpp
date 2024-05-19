#include<iostream>
#include<type_traits>


//1111 当输入值时int 类型 函数才成立
//如果是int 函数成立 返回默认第二个参数 void
//如果T != int,   T = void 函数声明非法
template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>> 
int process(T value) {
    std::cout << "Processing integral value: " << value << std::endl;
    return value;
}

//2222 第二个参数可以指定 std::enable_if_t<true, float> ture 时返回float
template<typename T, typename A = std::enable_if_t<std::is_integral<T>::value, float>>
A func( )
{
    return 1.3;
}



//333 根据情况选择返回值类型
template<bool a, typename B = std::enable_if_t<a, float>>
B return_float(B aa)
{
    return aa;
}


int main() {
    process(10); // This will work
    //process(3.14); // This will not compile because double is not integral
    std::cout<< func<int>() <<std::endl; //输入int 模板返回一个固定浮点数
    std::cout<< return_float<true> (1.33) <<std::endl; //控制参数 让模板返回一个固定浮点数
    std::cout<< return_float<false>(2.33) <<std::endl; //控制参数 让模板返回一个固定浮点数
    return 0;
}

 