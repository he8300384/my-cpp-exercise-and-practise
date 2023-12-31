/*
    2023 12 29 heqin cpp exersise practise factory 
    class without destructor memory leak!!! do not us in project
*/
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

//1111被创建类的接口
class abstract_toy {
    public: std::string name = "default";
    int price = 0;
    virtual void run() = 0;
    };

//2222要创建类的拓展
//! 3个步凑拓展
//! AAA追加 枚举
enum ToyType { FISH, LION, BRID, COCK, NUM_TOY_TYPES };//NUM_TOY_TYPES这个值天然是成员数量 以此获取 enum 成员数量
class fish:public abstract_toy{void run(){std::cout<<"my price =" << price <<"   fish can swiming\n";}};
class lion:public abstract_toy{void run(){std::cout<<"my price =" << price <<"   lion can runing\n" ;}};
class brid:public abstract_toy{void run(){std::cout<<"my price =" << price <<"   brid can flying\n" ;}};
class cock:public abstract_toy{void run(){std::cout<<"my price =" << price <<"   cock can runing\n" ;}};
//! BBB追加类实现

// 工厂类 根据需要负责生产
class factory
{ 
    public:
    static abstract_toy* make_toy(ToyType type, int price)
    {
        abstract_toy* f;
        switch (type)
        {
        case  FISH: f = new fish; f->price = price; return f;  break;
        case  LION: f = new lion; f->price = price; return f;  break;
        case  BRID: f = new brid; f->price = price; return f;  break;
        case  COCK: f = new cock; f->price = price; return f;  break;
        
        //! CCC  追加生产逻辑
        
        default: return nullptr; break;
        }  
    }
};

int main()
{
    std::vector<abstract_toy*> toys;
    //批量随机创建 对象
    for (int i =0; i<10;i++)
    {
        int randomIndex = rand() % NUM_TOY_TYPES ; //随机计算 ！技巧 NUM_TOY_TYPES这个值天然是成员数量 以此获取 enum 成员数量
        abstract_toy* b1 = factory::make_toy(ToyType(randomIndex), (randomIndex+1)*20);
        toys.push_back(b1);
    }

    //批量使用  
    for(auto i:toys){ i->run(); }

    //收尾
    for(auto i:toys){ delete i;}
    toys.clear();
};