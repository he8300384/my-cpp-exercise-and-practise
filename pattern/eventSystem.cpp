#include<iostream>
#include<queue>

//演示了一个最简的 事件队列系统
//无订阅和回调 在下一个案列实现


enum EventType // 用枚举 大项目到处都要包含这个枚举 一旦修改 全局编译  可以用GUID 表
{
    Jump,
    Shoot,
    Hit,
    Pause,
};

class Event
{
    public:
    EventType type;
    Event(EventType type): type(type){}
};

class EventQueue //最简功能的事件队列
{
    std::queue<Event> events;
public:
    void pushEvent(const Event& event)
    {
        events.push(event);
    }
    
    bool isEmpty() const
    {
        return events.empty();
    }

    Event popEvent()
    {
        Event event = events.front();
        events.pop();
        return event;
    }
};

class EventHandler //事件管理器 
{
    public:
    virtual void onEvent(const Event& event) = 0;
};

class PlayerEventHandler : public EventHandler
{
    public:
    void onEvent(const Event& event) override
    {
        switch(event.type)
        {
            case Jump:
                std::cout<< "player jump\n";
                break;
            case Shoot:
                std::cout<< "player shoot\n";
                break;
            default:
                break;
        }
    }
};

int main()
{
    EventQueue eventQueue;
    const Event& e1 = Event(Jump);
    const Event& e2 = Event(Shoot);
    const Event& e3 = Event(Jump);
    const Event& e4 = Event(Jump);

    eventQueue.pushEvent(e1);
    eventQueue.pushEvent(e2);
    eventQueue.pushEvent(e3);
    eventQueue.pushEvent(e4);

    PlayerEventHandler playerHandler;
    while(!eventQueue.isEmpty())
    {
        playerHandler.onEvent(eventQueue.popEvent());
    }
}