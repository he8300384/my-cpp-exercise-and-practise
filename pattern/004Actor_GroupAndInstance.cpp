#include<iostream>
#include<vector>
#include<string>
//我真在编写场景图 渲染actor 使用简单的案列 思考actor 组织关系

class Actor
{
public:
    static int id;
    std::string name;
    int age;
    Actor* father;
    Actor(std::string name):name(name){id++;}
    Actor(std::string name, int age):name(name), age(age){id++;}
    // 希望层级输出时有推进关系  当渲染引擎计算层次包围盒 或 层次变换时 道理类似
    // 当每个层次调用此函数时 累加空格数 形成层次效果
    void printSpace(int len)
    {
        for(int i= 0; i<len; i++)
        {
            std::cout<<" ";
        }
    }
    virtual void outputInfo(int space = 0)
    {
        printSpace(space);
        std::cout<< name <<" Age: "<< age <<std::endl;
    }
};

int Actor::id = 0;

class Group : public Actor
{
public:
    std::vector<Actor*> children;
    Group(std::string name):Actor(name){id++;}
    void addActor(Actor* actor)
    {
        children.push_back(actor);
        actor->father = this;
    }
    void outputInfo(int space = 0)override
    {
        printSpace(space);
        std::cout<<"----------------- "<<std::endl;
        printSpace(space);
        std::cout<<"Group name: "<<name<<std::endl;

        space += 5;
        for(auto child:children)
        {
            child->outputInfo(space);
        }

    }
};

class Instance : public Actor
{
public:
     
    
    Actor* actor;
    Instance(std::string name, Actor* actor):actor(actor), Actor(name) {id++;}
    void outputInfo(int space = 0)override
    {
        printSpace(space);
        std::cout<<actor->name<<"'s instance: "<<name<<std::endl;
    }
};

int main()
{
    
    Actor* actor1 = new Actor("actor1", 20);
    Actor* actor2 = new Actor("actor2", 30);
    Actor* actor3 = new Actor("actor3", 40);
    Actor* actor4 = new Actor("actor4", 10);
    Actor* actor5 = new Actor("actor5", 50);
    
    Group* group1 = new Group("group2");
    group1->addActor(actor5);

    Group* group = new Group("group1");
    group->addActor(actor1);
    group->addActor(actor2);
    group->addActor(actor3);
    group->addActor(group1);
    group->outputInfo();



    Instance* instance = new Instance("instance_form_actor1", actor1);

    Group* group2 = new Group("group3");
    group2->addActor(instance);
    group2->addActor(actor4);
    group2->addActor(group);
    group2->outputInfo();

    




}