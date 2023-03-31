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

unique_ptr<pepole> fuc()
{
    return unique_ptr<pepole>(new pepole(7, "he7"));
}

int main(){
    //构造
    pepole * p1 = new pepole(1, "he");    //裸指针          
    unique_ptr<pepole> pu1(p1); //第一种构建方式智能指针管理 p1 会析构

    unique_ptr<pepole> pu2(new pepole(2, "he2")); //第二种构建方式

    unique_ptr<pepole> pu3 = make_unique<pepole>(3, "he3"); //第三种狗构造方式 C14
    pu2->show();

    //特性
    unique_ptr<pepole> pu5(new pepole(5, "he5"));
    unique_ptr<pepole> pu6; 
    //pu6 = pu5;                                    //错误 不允许
    pu6 = unique_ptr<pepole>(new pepole(6, "he6"));//零时变量 允许
    pu6 = fuc();                                   //栈零时值 允许

    cout<< "释放智能指针\n";
    pu2 = nullptr;    

    cout<< "完毕\n";   

    //智能指针数组
      unique_ptr<pepole[]> pu7(new pepole[2]);
}