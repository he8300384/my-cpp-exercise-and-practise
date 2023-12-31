#include<iostream>
#include<string>
#include<vector>

//简单的观察者模式 

//1111 定义观察者接口
class Observer 
{
public:
    int m_ID;
    Observer(int id):m_ID(id){};
    virtual ~Observer(){} 
    virtual void update(std::string  message) = 0;
};

//2222 定义被观察者接口
class Subject
{
public:
    virtual ~Subject(){} 
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObserver(Observer* o) = 0; 
};

//33333 定义 具体观察者类
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


//44444 定义 具体被观察者类
class Sb:public Subject
{
    std::vector<Observer*> m_observers; //维护一个观察者指针列表 注意用地址
    std::string m_statue = "stop";
public:
    

    void registerObserver(Observer* o)
    {
        m_observers.push_back(o);
    }

    void removeObserver(Observer* o)
    {
        int postion = 0;
        for(auto i:m_observers)
        {

            if( i->m_ID == o->m_ID )
            {
                std::cout<<"delet observer:"<< i->m_ID <<std::endl;
                break;
            }
            postion++;
        }
        m_observers.erase(m_observers.begin() + postion);
    }

    void notifyObserver(Observer* o)
    {
         
            o->update(m_statue);
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


int main()
{
    //5555 创建 被观察实例
    Sb s;

    //6666 创建 一堆观察者
    Ob* aa1=new Ob(1);
    Ob aa2(2);
    Ob aa3(3);
    Ob aa4(4);

    //7777 关联 一堆观察者
    s.registerObserver(aa1);   
    s.registerObserver(&aa2);
    s.registerObserver(&aa3);
    s.registerObserver(&aa4);

   //! delete(aa1); // 模拟对 象被无意删除后 使用智能指针避免此类问题
    //8888 被观察者状态改变 观察者都被通知
    s.changeStatue("run"); 

    //9999 观察者列表维护
    s.removeObserver(&aa4);

    s.changeStatue("stop"); 
    s.changeStatue("other"); 

}