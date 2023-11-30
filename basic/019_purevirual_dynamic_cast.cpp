#include<iostream>
#include<string.h>

using namespace std;

class pepole
{
protected:
    string m_name = "默认";
    int m_age = 0;
public:
    
    virtual void speak()=0;   //注意virtual 
                
};

class boy:public pepole
{
public:
    int m_number;

    virtual void speak() override{cout<<"我是男孩\n";} //采用此写法可以方便读的时候 知道你在重载 和 重载一个虚函数    
    // void speak() {cout<<"我是男孩\n";}             作用一样的写法
};

class girl:public pepole
{
public:
    int m_number;

    void speak(){cout<<"我是女孩\n";}  
    void show(){cout<<"女孩说话\n";}   
};

int main()
{

     
    boy c;
    girl d;
    
    pepole* ptra = &c;//多态可使 基类指针调用相应派生类方法
    ptra->speak();
    cout<< "-------------------" <<endl;
    ptra =&d;
    ptra->speak();
    cout<< "-------------------" <<endl;

//Remember, dynamic_cast can only be used with pointers and references to classes, 
//and only works properly if the class has at least one virtual function (which makes it a polymorphic class).
    dynamic_cast<girl*>(ptra);//转换为派生类指针 以调用派生类独有函数  
    ptra->speak();
    cout<< "-------------------" <<endl;

    boy dd;
    dd.speak();
    
}