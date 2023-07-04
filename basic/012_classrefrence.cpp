#include<iostream>
#include<string.h>

using namespace std;

class dog
{
    public:
    string m_name ;
    dog(string name):m_name(name){cout<<"调用了dog 构造函数\n\n";}

    dog(const dog &d):m_name(d.m_name){ cout<<"调用了dog 拷贝构造函数\n\n";}
     
};



class pepole
{
    public:
    dog m_pet;
    string m_name;
    pepole(string name,dog& pet):m_name(name),m_pet(pet)//此处引用可避免多次拷贝构造
    {cout<<"调用了pepole 构造函数\n\n";}
};

int main()
{
       dog hauhua ("huahua");
       
        
       pepole ac("ac", hauhua);
}