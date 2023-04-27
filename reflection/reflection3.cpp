/* 
2023 04 28
这个反射方法基于 继承static_cast 宏
使用宏包裹需要添加反射的属性 并且需要继承包含了属性操作函数指针的基类
属性操作函数 在类外定义 使用基类指针转换为子类指针 调用具体子类属性
操作函数的指针列表收录在基类vector组内 基类有统一遍历调用数组内函数的方法

优势：
    逻辑实现简单
    对与只需要批量 序列化 属性的情况够用

劣势：
    侵入式
    属性操作是批量的无法单独操控 
    基类 辅助添加类 操作函数 改写量不小

*/
#include<iostream>
#include<sstream>
#include<functional>
#include<string>
#include<vector>

class BaseRefect;

using FUNC = std::function<void(BaseRefect *)>; //定义函数指针 以灵活指向 不同的属性操作函数
using ALLMembers = std::vector<FUNC>;           //定义指针数组 存储子类 所有属性 一个操函数的指针

//4444 定义基类用于存储 和添加子类新引入属性的 各种操作函数
class BaseRefect
{
    ALLMembers to_write; //所有属性的写函数
    ALLMembers to_read; //所有属性的读取函数
    void push_func(ALLMembers &member, FUNC &func){member.push_back(func);}
public:
    void doWrite(){for(auto &f : to_write) f(this);} //遍历函数指针数组 输出每一个属性

    void doRead(){for(auto &f : to_read) f(this);} //遍历函数指针数组 读取每一个属性

    void add(FUNC &write, FUNC &read) //往所有队添加函数指针
    {
        push_func(to_write, write);
        push_func(to_read, read);
    }
};

//3333  用一个操作函数添加类操作this指针 调用基类添加方法 为子类新加属性添加操作函数
class AutoAdd
{
public: 
    AutoAdd(BaseRefect *t, FUNC write, FUNC read){t->add(write, read);}
};

//2222.2宏定义具体的属性操作函数   
#define WRITE(data)\
    [](BaseRefect *t){auto real_this = static_cast<decltype(this)>(t); std::cout<< real_this->data <<std::endl;} //

std::stringstream s; //通过流写入属性值

#define READ(data)\
    [](BaseRefect *t){auto real_this = static_cast<decltype(this)>(t); s >> real_this->data;}    

//2222.1 展开宏 用一个类构造函数 传入属性操作函数
#define REFLECT(type, data)\
    type data;\
    AutoAdd __auto__add_##data{this, WRITE(data), READ(data)} //当宏被插入任意继承了反射父类的子类中时 它就搜集this指针为子类添加变量的操作函数

//1111 普通类继承 反射用基类 并用宏注册字段属性
class RefectClass : public BaseRefect 
{
    REFLECT(int, a);
    REFLECT(std::string, name);
    REFLECT(int, money);
};

int main()
{
    RefectClass a;
    s << 22 << "heqin\n" << 11; //使用sstream流写数据
    a.doRead();                 //使用sstream流写数据
    a.doWrite();    

    s.clear();  //清理流
    s << 33 << "heqin2\n" << 44;//改写数据
    a.doRead();                 //改写数据
    a.doWrite(); 
    
}