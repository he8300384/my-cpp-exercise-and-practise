#include<iostream>
#include<string.h>

using namespace std;

template <class T1 , class T2=int>//类模板 可以指定缺省数据类型
class pepole
{
protected:
    T1 m_name = "默认";
    T2 m_age = 0;
public:
    pepole(T1 name, T2 age): m_name(name), m_age(age){cout<<"构造类\n";}
    virtual void func(){cout<<"模板类func\n";}   //注意virtual 
            void func2();    
};

template <class T1 , class T2 >//可在外 实现模板类函数
void pepole<T1, T2>::func2()
 {cout<<"模板类func2\n";}   


//特化class模板化  可以部分参数特化  
 template<>
 class pepole<int, string>
 {
    protected:
    string m_name = "默认";
    int m_age = 0;
public:
    pepole(string name, int age): m_name(name), m_age(age){cout<<"构造类\n";}
    virtual void func(){cout<<"模板类func\n";}   //注意virtual 
            void func2();    

 };

int main()
{
    pepole<string, int> a("ad", 12); //类模板要显式指定类型 再创建
    a.func2();

    pepole<string, string> b("bb", "13");
    b.func2();

     pepole<string, string> *ptr = new pepole<string, string>("sdf", "121"); //用模板类new

     ptr->func2();

     delete ptr;
    
}