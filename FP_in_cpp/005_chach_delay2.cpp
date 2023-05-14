#include<iostream>
#include<thread>
#include<mutex>
#include<functional>

using namespace std;

//带缓存的延迟执行的模板类 可优化函数调用时间 屏蔽非纯函数输入模板类导致的问题 \
 
/*
//template <typename F>
//class lazy_func
//{
//private:
//    F m_function;                                   //存储输入的函数
//    mutable decltype(m_function()) m_cache;         //存储输入函数运行结果 
//    mutable std::once_flag m_cache_flag;            //单次执行标签
//public:
//    lazy_func(F func):m_function(func){cout<< "创建了一个函数";} //构造      
//     
//    operator const decltype(m_function()) & () const
//    {     
//        //只执行一次 也可避免多线程同时修改
//        std::call_once(m_cache_flag, [this]{m_cache = m_function();});         
//        //其余执行 直接返回缓存的结果
//        return m_cache;
//    }   
//};
 */

template <class F>
class lazy_func
{
private:     
    F m_function;                               //存储输入的函数
    mutable  decltype( m_function()) m_saved;    //存储输入函数运行结果 
    mutable std::once_flag m_cache_flag;        //单次执行标签
public:
    lazy_func(F func):m_function(func){cout<< "创建带缓存惰性求值函数\n";} //构造      
   
    auto run()
    {     
        //只执行一次 也可避免多线程同时修改
        std::call_once(m_cache_flag, [this]{m_saved =  m_function();});         
        //其余执行 直接返回缓存的结果
        return m_saved;
    }   
};

//制造实例 自动推算类型   输入函数是模板函数时 c17 以下不支持自动推断
//实列作为函数返回值时注意移动语义 输入的函数也要实现右值引用
template <typename F>
inline lazy_func<F> make_lazy_func(F&& func)
{
    return lazy_func<F>(std::forward<F>(func)); 
}
  
int main()
{
    int c = 1,d = 2;

    auto add_cd = make_lazy_func([&](){return c + d;}); //生成一个测试函数

     cout<<"一次运行结果："<< add_cd.run() << endl;
     
    c = 3; d = 4; //改版了值结果并不变

    cout<<"二次运行结果："<< add_cd.run() << endl;
}


