#include <memory>
#include <string>
#include <iostream>

using namespace std;

class pepole
{
    int m_num;
    string m_name;
    int m_money;
    public:
    pepole():m_money(12),m_name("defaut"),m_num(1){}
    pepole(int num, string name):m_num(num), m_name(name), m_money(12){cout<<m_name <<" 调用构造\n";}
    ~pepole(){cout<<m_name<<" 调用析构\n";}
    pepole(const pepole & p):m_num(p.m_num), m_name(p.m_name), m_money(p.m_money){cout<<m_name<<" 调用拷贝构造\n";}

    void show(){cout <<" "<< m_num <<" "<< m_name <<" "<< m_money << endl;}
};

 void delete1(pepole* ptr)
 {
    cout << "调用自定义删除器delete1\n";
    delete ptr;
 }

 struct delete2{
    void operator()(pepole* ptr)
    {
        cout << "调用自定义仿函数删除器delete2\n";
        delete ptr;
    }
 };

int main(){
    shared_ptr<pepole> p1(new pepole(1,"he"));//无删除器

    shared_ptr<pepole> p2(new pepole(1,"he"), delete1); //函数删除器

    shared_ptr<pepole> p3(new pepole(1,"he"), delete2()); //仿函数  删除器

    //unique_ptr 稍麻烦
     unique_ptr<pepole,decltype(delete1)*> p14(new pepole(1,"he"),delete1); 
     unique_ptr<pepole,void(*)(pepole*)> p15(new pepole(1,"he"),delete1); 

}