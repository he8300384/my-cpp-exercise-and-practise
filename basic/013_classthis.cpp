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

    const pepole& older(const pepole& pe) const
    {
        if(pe.m_age > m_age) return pe;
        else return *this; //注意解引指针 以使用引用
    }
    void show()
    {
        cout << "名字 :" << m_name <<"  年龄 :"<< m_age <<endl;
    }
};

int main()
{
    pepole a("大卫",12), b("二哈",41),c("三杀",22),d("古德",32);

    pepole older =  a.older(b).older(c).older(d); //链式比较

    cout<< "最大年纪的人是: ";
    older.show();    
}