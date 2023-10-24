#include<iostream>
#include<string.h>

using namespace std;

//类的静态成员 是所有实例共享的
//其初始化 也要在类声明 以外

//n C++, a static member of a class is a member that is shared by all objects of the class. 
//It is not associated with any particular object of the class. It is declared within the class but is defined outside the class.
class pepole
{
    public:
    static int m_number;
    int m_age;
    string m_name;

    static void show_number(){cout << "实例个数 :" << m_number <<endl;}

    pepole(string name,int age):m_name(name),m_age(age) 
    {
        m_number++;
        cout<<"调用了pepole 构造函数\n\n";
    }
    ~pepole(){m_number--;};

    const pepole& older(const pepole& pe) const
    {
        if(pe.m_age > m_age) return pe;
        else return *this; //注意解引指针 以使用引用
    }
    void show()
    {
        cout << "名字 :" << m_name <<"  年龄 :"<< m_age <<"  实列数量 :"<<m_number <<endl;
    }
};

int pepole::m_number = 0;//静态成员初始化

int main()
{
    pepole::show_number(); //静态成员无需实例 可直接调用

    pepole a("大卫",12), b("二哈",41),c("三杀",22),d("古德",32);

    pepole older =  a.older(b).older(c).older(d); //链式比较

    cout<< "最大年纪的人是: ";
    older.show();    
    a.~pepole();
    older.show(); 
}