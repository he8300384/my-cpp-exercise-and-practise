/*
    2023 12 29 heqin cpp exersise practise abstract factory 
    class without destructor memory leak!!! do not us in project
*/
#include<iostream>
#include<string>

//!!!没有实现析构 内存泄漏
//1111 定义抽象工厂以此为基础 拓展复数工厂
class abstract_factory
{
    public: 
    std::string name = "abstract factory";  
    virtual void set_weapon(std::string type) = 0;
    virtual void set_enging(std::string type) = 0;
    virtual void show() = 0;
};

//2222 定义或者拓展  产品要用到的 不同部件类 
class abstract_weapon{ public: virtual void use() = 0;}; //不同的类可配置不同武器
class Biggun        :public abstract_weapon{ public: void use(){std::cout<<" Biggun__booooooo  ";}};
class Smallgun      :public abstract_weapon{ public: void use(){std::cout<<" Smallgun__bibibi  ";}};
class Emptygun      :public abstract_weapon{ public: void use(){std::cout<<" no gun equiped    ";}};
//!  11111111可追加部件类型

class abstract_enging{ public: virtual void use() = 0;}; //不同的类可配置不同引擎
class Bigenging     :public abstract_enging{ public: void use(){std::cout<<" Big enging__wowow  ";}};
class planenging    :public abstract_enging{ public: void use(){std::cout<<" planenging__sosos  ";}};
class litenging     :public abstract_enging{ public: void use(){std::cout<<" Lit enging__ziziz  ";}};
class Emptyenging   :public abstract_enging{ public: void use(){std::cout<<" no enging equiped  ";}};
//!  11111111可追加部件类型

//3333333 工厂只有一个时抽象工厂是无意义的  抽象意义在于复数工厂！！！ 组装不同部件 形成产品 组装的物品可定制或自动构造
class plan_factory :public abstract_factory
{
public:
    
    abstract_weapon* weapon = nullptr;
    abstract_enging* enging = nullptr;
    void set_weapon(std::string type){         
        if      (type == "Biggun")     weapon = new Biggun; 
        else if (type == "Smallgun")   weapon = new Smallgun;    
        else weapon = new  Emptygun;    
        }
    void set_enging(std::string type){         
        if      (type == "Bigenging ")  enging = new Bigenging; 
        else if (type == "planenging")  enging = new planenging; 
        else enging = new Emptyenging;          
        }
    void show(){std::cout<<name <<"  runing with: ";  weapon->use(); enging->use();std::cout<< "\n";}
};

//33333333不同工厂组装不同部件 形成产品 组装的物品可定制或自动构造
class tank_factory : public abstract_factory
{
public:
     
    abstract_weapon* weapon = nullptr;
    abstract_enging* enging = nullptr;
    void set_weapon(std::string type){         
        if      (type == "Biggun")     weapon = new Biggun; 
        else if (type == "Smallgun")   weapon = new Smallgun;       
        else weapon = new  Emptygun;       
        }
    void set_enging(std::string type){         
        if      (type == "Bigenging")  enging = new Bigenging; 
        else if (type == "litenging")  enging = new litenging;
        else enging = new Emptyenging;           
        }
    void show(){std::cout<<name <<"  runing with: ";  weapon->use(); enging->use();std::cout<< "\n";}
};

//! 22222222可追加不同行为的工厂

//4444444管理工厂
class factory_seter
{
public:
    static abstract_factory* set(std::string factory)
    {
        if      (factory == "plan_factory")   return new plan_factory; 
        else if (factory == "tank_factory")   return new tank_factory; 
        //!2222222222可追加不同行为的工厂
        else return nullptr;
    }
};

int main()
{
    std::cout<<"1hi"<<std::endl;

    //55555用工厂创建器创建工厂
    abstract_factory* tank_MK1 =  factory_seter::set("tank_factory");  
    abstract_factory* plan_CC1 =  factory_seter::set("plan_factory");
    abstract_factory* plan_CC2 =  factory_seter::set("tank_factory"); //! 演示 配置错误的容忍性
    
    //666666配置组件 并使用 1
    tank_MK1->set_weapon("Smallgun");
    tank_MK1->set_enging("Bigenging");
    tank_MK1->name = "tank_MK1";
    tank_MK1->show();
    
    //666666配置组件 并使用 2
    plan_CC1->set_weapon("Biggun");
    plan_CC1->set_enging("planenging");
    plan_CC1->name = "plan_CC1";
    plan_CC1->show();

    //666666配置组件 并使用 2
    plan_CC2->set_weapon("Biggun");
    plan_CC2->set_enging("planenging");
    plan_CC2->name = "plan_CC2";
    plan_CC2->show();

    //! 4444444根据追加的类型和工厂 追加业务原来代码不变！！！！！！！
}