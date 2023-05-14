//c++ 柯里化

#include <functional>
#include <iostream>

using namespace std;

//演示了 通用比较年龄 的仿函数
class older_than{
    int m_limit;
public:
    older_than(int limit):m_limit(limit){}
    template<typename T>
    bool operator()(T&& object) const
    {   
        bool i = std::forward<T>(object).age  > m_limit;
        if(i) cout<<"年龄大于 " << m_limit << endl;
        else  cout<<"年龄小于 " << m_limit << endl;
        return i;
     }    
};

//几个不同的类
class people {public: int age=13;};
class dog {public: int age=4;};
class car {public: int age=3;};

auto main() -> int
{
     people p; dog d; car c;
    //创建比较 仿函数 
    older_than  older_than11(11);
    //作用于于所有含有.ag属性的实例
    older_than11(p);
    older_than11(d); 
    older_than11(c);
     
}