#include <unordered_map>
#include <vector>
#include <functional>
#include <iostream>
#include <string>

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

/*
1. Centralized Event Manager
A centralized event manager can handle the registration of event listeners 
and the dispatching of events to the appropriate subsystems or entities.
*/

class EventManager {
private:
    std::unordered_map<EventType, std::vector<std::function<void(const Event&)>>> listeners;

public:
    void subscribe(EventType type, std::function<void(const Event&)> listener) {
        listeners[type].push_back(listener);
    }

    void dispatch(const Event& event) {
        auto& handlers = listeners[event.type];
        for (auto& handler : handlers) {
            handler(event);
        }
    }
};

/*
. Define Event Types and Event Class
As previously defined, use an EventType enumeration and an Event class to encapsulate event data.
3. Subsystem and Entity Event Handling
Subsystems and entities that need to handle events will register themselves with the EventManager.
*/

//组件模式一样 业务集成到组件中 注册到中心事件管理器
class Player {
    std::string name ;
public:
    Player(std::string n):name(n){}
//! 自己处理自己业务 编译理解
    void handleJump(const Event& event) {
        std::cout<<name<< " player jump\n";
    }
    void handleHit(const Event& event) {
    std::cout<<name<< " player Hit\n";
    }

//! 注册自己到全局事件管理器
    void registerEvents(EventManager& manager) {
        manager.subscribe(Jump, [this](const Event& event) { this->handleJump(event); });
        manager.subscribe(Hit,  [this](const Event& event) { this->handleHit (event); });
    }
};


int main()
{
    //单例一个事件管理器
    EventManager manager;

    //若干组件 对象 子系统 注册
    Player player("aaa");
    player.registerEvents(manager);

    Player player2("bbb");
    player2.registerEvents(manager);

    Event jumpEvent(Jump);
    manager.dispatch(jumpEvent);

    Event HitEvent(Hit);
    manager.dispatch(HitEvent);
}