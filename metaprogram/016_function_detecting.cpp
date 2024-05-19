#include<type_traits> //使用标准 true falsse
#include<iostream>

//测试素材
bool func(int){std::cout<<"普通函数"<<std::endl;}
struct test
{
    int a;
    void out(int a){std::cout<<"成员函数"<<std::endl;}
    void put(int a){std::cout<<"成员函数"<<std::endl;}
};


//去除指针
template<typename T>
struct remove_pointer;

template<typename T>
struct remove_pointer<T*>{using type = T;};



//去除const
template<typename T>
struct remove_const;

template<typename T>
struct remove_const<const T>{using type = T;};



//获取函数
template<typename T>
struct function_traits; 

template<typename Return, typename... Args>
struct function_traits<Return(*)(Args...)>
{
    using return_type = Return;
    //using Args = Args...; 这样写不行
    using param = std::tuple<Args...>;//暂时这样写
    static constexpr bool is_in_class = false; //描述在类里与否

};

template<typename className, typename Return, typename... Args> //! 成员函数偏特化
struct function_traits<Return(className::*)(Args...)>
{
    using return_type = Return;
    //using Args = Args...; 这样写不行
    using param = std::tuple<Args...>;//暂时这样写
    using class_name = className;  //描述在所在类型信息
    static constexpr bool is_in_class = true; //描述在类里与否
};

// 获取成员变量
template<typename>
struct variable_traits;

template<typename className, typename T>
struct variable_traits<T(className::*)>
{
    using type = T;
    using class_name = className;
    static constexpr bool is_in_class = true; //描述在类里与否
};

//存储类的信息 //! 很多地方包括 视频 书 都只能宏实现
template<typename T>
struct TypeInfo;

#define BEGIN_CLASS(T)                      \
    template<> struct TypeInfo<T>{          \
        using type = T;

#define FUNCTIONS(...) using fuctions = std::tuple<__VA_ARGS__>;//需要多个函数用一个多参数模板塞进元组

#define END_CLASS()  };

//宏展开 这几行可以压缩得更简洁 类似许多人的实现
BEGIN_CLASS(test)
FUNCTIONS(function_traits<decltype(&test::out)>,
          function_traits<decltype(&test::put)>)
END_CLASS()




int main()
{
    //获取普通函数
    auto ptr  = &func;
    using founction_info1 = function_traits<decltype(ptr)>;
    using reture_type1 = founction_info1::return_type;
    ptr(1); 

    //获取成员函数
    auto mptr = &test::out;
    using founction_info2 = function_traits<decltype(mptr)>;
    using reture_type1 = founction_info1::return_type;
    test t;
    (t.*mptr)(1);//! 注意成员函数调用需要实例

    std::cout<<mptr<<std::endl;//! 成员函数地址不是实际地址 可能是虚表编号等

    //bool(      * )(void) //普通函数指针
    //bool(test::*p)(void) //成员函数指针
    //bool(test::*p)       //成员变量指针

    //获取成员变量
    using variable_info =  variable_traits<decltype(test::a)>;
    
    using type = TypeInfo<test>;
    //std::cout<<variable_info::class_name<<std::endl;

}

