#include<iostream>
#include<functional>

using namespace std;

//！ 这个不用看了 直接看后面一个文件 实现简答太多  不清楚这么多函数的目的 这本书作者逻辑很罗嗦 ？
//带缓存的延迟执行的模板类 可优化函数调用时间 屏蔽非纯函数输入模板类导致的问题 cnm真他妈绕能简单点写吗
//总之用一个属性A 存储第一次调用run时的默认操作 此时输入的函数结果被移入属性 B  
//以后多次调用run 直接从属性B 取函数运行 
template <class T>
class Delay
{
    T const & (*m_subRotine)(Delay *); // A  第一次调用run会使用 1111 其b步凑会将指针换为 3333 以后调用run 流程切换为3333   
    mutable T m_recordedFunc;          // B  第一次调用run 记录输入的函数的结果 再次运行run直接给结果
    function<T()> m_func;              // C  输入函数


    //1111 构造时装载此函数的地址给私有函数指针 A
     static T const & defaultSubroutine(Delay *d) 
    { 
        return d->defaultRecording(); 
    }

    //2222 接1111步凑 第一次调用run时 改变 B 和 A 属性
     T const & defaultRecording()
    {   
        m_recordedFunc = m_func();      //   a 调用输入的函数结果 存到 B
        m_subRotine =&runSubroutine;    //！ b 将静态函数3333 存到 A 以后调用run 省略过程
        cout<< "函数结果记录完毕 结果是: "<< m_recordedFunc <<endl; 
        return  m_recordedFunc;          //   c 调用 B 内函数执行存入的函数 ？为什么多一次调用此时B有值不直接返回
    }

    // 3333  第一次调用run后 此函数被输入到 属性 A  第二次调用run 流程 从这里开始 
    static T const & runSubroutine(Delay *d)
    {  
        return d->runRecording();
    }

    // 4444  以后每次调用run 都会返回记录的属性 B 省时！！！！
    T const & runRecording()
    {   
        cout<< "直接取缓存值  :"<< m_recordedFunc <<endl;
        return m_recordedFunc;
    }


public:
    Delay(function<T()> func) : m_func(func),       //输入一个函数
                m_subRotine(&defaultSubroutine),    //把静态成员函数1111 地址传递给 私有成员 A  run会调用它 1111只使用一次以提升性能
                        m_recordedFunc(T())         //属性C 预设一个值
                        {}

    T run(){ return m_subRotine(this);}              //第一次调用记录函数到属性B 以后调用直接使用内部备份版  不会因为 函数不纯 导致错误
};

int main()
{
    int a = 22, b = 5;
    int bug = 1; 

    Delay<int> multiply( [&](){cout<<bug<<" * "<<a<<" * "<<b <<" ";
        return bug * a * b;} ); //引用接收所有参数 此时引入bug 函数非纯
     
    for(int i = 0; i < 5;i++)
    {
        cout << "现在运行函数" << i+1 <<"次" <<"\n";
        ++bug;//模拟位置的值修改导致非纯函数性质变化
        multiply.run();//多次运行 由于存储类第一次run的函数 
    }
                              
}