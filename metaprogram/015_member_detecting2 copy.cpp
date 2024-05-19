#include<type_traits> //使用标准 true falsse
#include<iostream>

// 111 基础模板
template<typename T> 
    struct IsBaseType : std::false_type{};

#define IS_BASE_TYPE(type) \
    template<> struct IsBaseType<type> : std::true_type{};  //2222 宏化构造模板

    //3333 可以定义各类std原始类型模板重载
    
    IS_BASE_TYPE(void) //重载模板 1
    IS_BASE_TYPE(int)  //重载模板 2
    IS_BASE_TYPE(bool) //重载模板 3
    IS_BASE_TYPE(long) //重载模板 4
    //若干 。。。自行添加

#undef IS_BASE_TYPE

//4444 测试函数
template<typename T>
void test(T const&)
{
    if(IsBaseType<T>::value)
        std::cout<< "is  base type" <<std::endl;
    else
        std::cout<< "not base type" <<std::endl;
}




int main()
{
    //类型是否有
     std::cout<< IsBaseType<int>::value <<std::endl;
     std::cout<< IsBaseType<float>::value <<std::endl;

     test("aaa");
}

