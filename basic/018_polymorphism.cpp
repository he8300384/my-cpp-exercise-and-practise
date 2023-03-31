#include<iostream>
#include<string.h>

using namespace std;

class pepole
{
protected:
    string m_name = "默认";
    int m_age = 0;
public:
    
    virtual void speak(){cout<<"我是人\n";}   //注意virtual 
                
};

class boy:public pepole
{
public:
    int m_number;

    void speak(){cout<<"我是男孩\n";}     
};

class girl:public pepole
{
public:
    int m_number;

    void speak(){cout<<"我是女孩\n";}     
};

int main()
{

    pepole a;
    boy c;
    girl d;
    
    pepole* ptra = &c;//多态可使 基类指针调用相应派生类方法
    ptra->speak();
    ptra =&d;
    ptra->speak();
    
}