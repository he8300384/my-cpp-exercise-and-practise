#include <memory>
#include <string>
#include <iostream>

using namespace std;

/*std::shared_ptr is a smart pointer in the C++ Standard Library that retains shared ownership of an object through a pointer. 
Several shared_ptr objects may own the same object, and the object is destroyed and its memory deallocated when the last shared_ptr owning the object is destroyed.

shared_ptr是一种智能指针（smart pointer），作用有如同指针，但会记录有多少个shared_ptrs共同指向一个对象。这便是所谓的引用计数（reference counting）。
一旦最后一个这样的指针被销毁，也就是一旦某个对象的引用计数变为0，这个对象会被自动删除。这在非环形数据结构中防止资源泄露很有帮助。
*/

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
    pepole * p1 = new pepole(2, "he");    //裸指针          
    shared_ptr<pepole> pu1(p1); // 
    
    shared_ptr<pepole> pu3 = make_shared<pepole>(3 , "he3"); //推荐构造方式

    shared_ptr<pepole> pu2 = pu1 ; //可以拷贝构造
    shared_ptr<pepole> pu4 (pu3);

    cout<< pu1.use_count() <<endl;
    
}