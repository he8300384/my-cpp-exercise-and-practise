#include<iostream>
#include<string.h>

using namespace std;

class pepole
{
protected:
    string m_name = "默认";
    int m_age = 0;
public:
    pepole(){cout<<"基类构造1\n";}                                             //构造函数 1
    pepole(string name, int age):m_name(name),m_age(age){cout<<"基类构造2\n";} //构造函数 2
    pepole(string name):m_name(name),m_age(10){cout<<"基类构造3\n";}           //构造函数 3
    
    void func(){cout<<"基类func\n";}        
};

class boy:public pepole
{
public:
    int m_number;

    boy(){cout<<"派生构造1\n";}
    boy(int number,string name, int age):m_number(number),pepole(name,age)  {cout<<"派生构造2\n";}
    boy(int number,string name):m_number(number),pepole(name)               {cout<<"派生构造3\n";}

    void show(){cout<< m_name<<" "<< m_age << " " << m_number << endl;}

    void func(){cout<<"子类func\n";}       
};

int main()
{
     boy b(1,"aa");
     b.show();

     boy v(2,"dd",4);
     v.show();

     boy c;
     c.show();

     c.func();
     c.pepole::func();//如此调用基类已经屏蔽的函数
}