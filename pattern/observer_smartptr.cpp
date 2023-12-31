#include<iostream>
#include<string>
#include<vector>
#include <memory> // for std::shared_ptr and std::weak_ptr

//简单的观察者模式 智能指针版 避免 被观察者调用 被无意释放的观察者

//1111 定义观察者接口
class Observer 
{
public:
    int m_ID ;
    Observer(int id):m_ID(id){};
    virtual ~Observer(){} 
    virtual void update(std::string  message) = 0;
};

class Ob:public Observer
{
    public:

    Ob(int id):Observer(id){} //父类参数初始化
    //根据被观察者状态 维护的不同业务回馈
    void update(std::string  message)
    {
        if (message == "run")
        {
            std::cout<< m_ID << "  follow run\n";
            return;
        }

        if (message == "stop")
        {
            std::cout<< m_ID << "  follow stop\n";
            return;
        }

        else
            std::cout<< m_ID << "  do nothing\n";
    }
};

//2222 定义被观察者接口
class Subject
{
public:
    virtual ~Subject(){} 
    virtual void registerObserver(std::shared_ptr<Observer> o) = 0;
    virtual void removeObserver  (std::shared_ptr<Observer> o) = 0;
    virtual void notifyObserver  (std::weak_ptr<Observer>  o) = 0; 
};

// Change the observer list in the Subject class to hold weak_ptr
class Sb:public Subject
{
    std::vector<std::weak_ptr<Observer>> m_observers; // Use weak_ptr instead of raw pointer
    std::string m_statue = "stop";

public:
    void registerObserver(std::shared_ptr<Observer> o)
    {
        m_observers.push_back(o);
    }

    void removeObserver(std::shared_ptr<Observer> o)
    {
        int postion = 0;
        for(auto i:m_observers)
        { 
             
            // if( *i.m_ID == o->m_ID )
            // {
                // std::cout<<"delet observer:"<< i->m_ID <<std::endl;
                // break;
            // }
            // postion++;
        }
        m_observers.erase(m_observers.begin() + postion);

    }

    void  notifyObserver(std::weak_ptr<Observer> o)
    {
        if(auto observer = o.lock()) //! 判断对象还存在否 If the observer still exists
        {
            observer->update(m_statue);
        }
    }

     //一旦状态改变 依次通知观察者
    void changeStatue(std::string statue) 
    {
        m_statue = statue;
        std::cout<<"Subject on statue: "<<statue <<std::endl;
        for(auto i:m_observers)
        {   
            notifyObserver(i);
        }
     }
     
};


// In main, use shared_ptr when creating observers
int main()
{
    //5555 创建 被观察实例
    Sb s;

    //6666 创建 一堆观察者
    std::shared_ptr<Ob> aa1 = std::make_shared<Ob>(1);
    std::shared_ptr<Ob> aa2 = std::make_shared<Ob>(2);
    std::shared_ptr<Ob> aa3 = std::make_shared<Ob>(3);
    std::shared_ptr<Ob> aa4 = std::make_shared<Ob>(4);
     
     
     

    //7777 关联 一堆观察者
    s.registerObserver(aa1);   
    s.registerObserver(aa2);   
    s.registerObserver(aa3);   
    s.registerObserver(aa4);   
     
     
     

    aa2.reset(); //!模拟无意删除Instead of delete, use reset to release the memory

    //8888 被观察者状态改变 观察者都被通知
    s.changeStatue("run"); 

    //9999 观察者列表维护
    s.removeObserver(aa4)  ;

    s.changeStatue("stop"); 
    s.changeStatue("other"); 

}