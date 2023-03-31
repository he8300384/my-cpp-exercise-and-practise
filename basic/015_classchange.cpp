#include<iostream>
#include<string.h>

using namespace std;

 

class pepole
{
    public:
    int m_age;
    string m_name;
    pepole(string name,int age):m_name(name),m_age(age) 
    {cout<<"调用了pepole 构造函数\n\n";}
    pepole(int age):m_age(age),m_name("默认值") 
    {cout<<"调用了转换函数"<< endl;}

    operator int(){return m_age;}    //转换函数 //explicit 加前面可以让转换函数失效
    operator string(){return m_name;} //转换函数
};

int main()
{              
    
    pepole ac = 8; //隐式转换式构造
    int c = ac;//隐式转换
    string b = ac;

    cout << c <<"  "<<  b <<endl;
}