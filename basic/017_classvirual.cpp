#include<iostream>
#include<string.h>

using namespace std;

class pepole
{
protected:
    string m_name = "默认";
    int m_age = 0;
public:
    
    virtual void func(){cout<<"基类func\n";}   //注意virtual 
            void func2(){cout<<"基类func2\n";}       
};

class boy:public pepole
{
public:
    int m_number;

    void func(){cout<<"子类func\n";} 
    void func2(){cout<<"基类func2\n";}       
};

int main()
{

    pepole a;
    boy c;
    

    pepole* ptra = &a;//如果基类不是virtual的方法 基类指针无法调用到派生类方法
    ptra->func(); 
    ptra->func2();
    ptra = &c;
    ptra->func(); 
    ptra->func2();
}