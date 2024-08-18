#include<iostream>
#include<vector>
#include<string>
#include<fstream>
//我真在编写场景图 渲染actor 使用简单的案列 思考actor 组织关系

class Actor
{
public:
    static int num;
    int id;
    std::string name;
    int age;
    Actor* father;
    Actor(std::string name):name(name){id = num ; num++;}
    Actor(std::string name, int age):name(name), age(age){id = num ; num++;}
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
        std::cout<< name <<"  Age: "<< age <<" ID: "<< id <<std::endl;
    }
    void changeName(std::string name)
    {
        this->name = name;
    }

    virtual Actor* copy()
    {
        return new Actor(name, age);
    }
    
};

int Actor::num = 0;

class Group : public Actor
{
public:
    std::vector<Actor*> children;
    Group(std::string name):Actor(name){ }
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
        std::cout<<"Group name: "<<name<<" ID: "<< id <<std::endl;

        space += 7;//! 递归调用时 空格数增加
        for(auto child:children)
        {
            child->outputInfo(space);
        }
    }

    Actor* copy()override
    {
        Group* group = new Group(name);
        for(auto child:children)
        {
            group->addActor(child->copy());
        }
        return group;
    }
};

class Instance : public Actor
{
public:
     
    
    Actor* actor;
    Instance(std::string name, Actor* actor):actor(actor), Actor(name) { }
    void outputInfo(int space = 0)override
    {
        printSpace(space);
        std::cout<<actor->name<<"'s instance: "<<name<<" ID:"<< id <<std::endl;
    }

    Actor* copy()override
    {
        return new Instance(name, actor);
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

    // 修改actor1的名字 会影响到instance的输出
    actor1->changeName("actor1_change1");
    std::cout<<"\nAfter change actor1's name"<<std::endl;
    group2->outputInfo();

    // 复制group2 会复制所有group中的actor
    actor1->changeName("actor1_change2"); //实例中的actor1仍然指向源头actor1
    actor1->outputInfo();
    group2->copy()->outputInfo();


    return 0;

}