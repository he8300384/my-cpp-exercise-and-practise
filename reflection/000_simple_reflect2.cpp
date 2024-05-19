//自己写得一个固化反射 序列化案例 
//难点在于支持各种类和 自动识别信息

#include<iostream>
#include <fstream>
#include <sstream>
#include<map>
 
// 1.2  用一个结构体记录每个成员变量信息 
//      不同成员变量信息不一样 class enum int  ... 这个得是个模板类 我日  
struct memberInfo
{
    std::string type; //变量类别
    //map中存储名字 const char* name; //变量名  offsetof(class, variable)可用于计算成员在类中的位置 从而调用它
    void* memberAddress;
    size_t size;      //变量大小 
};

// 1.1 那么用一个结构体记录 类信息
struct classInfo
{
    std::string name; //类名
    void* address;    //用于访问的地址
    void* father;     //父类
    std::map<std::string, class memberInfo> member; //成员变量 变量有各种类型 这里又得搞个结构体
};

// 111 我有个类c++需要自己额外申请空间记录 成员信息   MMP c++脑壳有病 
struct Dog
{
    int age;
    float price;
    class classInfo m_info;//每个实例信息
    void InitInfo(std::string name);//填写类型信息 //todo 怎么保证生成一个实例自动注册信息呢
};

// 222 那么我们得填写以上信息 //todo 怎么保证自动填写呢 这里全是手动得 当然可以每一种情况定义一个函数重载 实际又得用模板
void Dog::InitInfo(std::string instanceName)
{
    m_info.name = instanceName;
    m_info.address = this;
    m_info.father = nullptr;
    //注册每一个成员
    m_info.member.emplace("age",    memberInfo{"int",   (char*)this + offsetof(Dog, age),   sizeof(int)  });
    m_info.member.emplace("price",  memberInfo{"float", (char*)this + offsetof(Dog, price), sizeof(float)});
}

// 333 可以使用工厂类或者 工厂函数 构造函数 创建实例
Dog* newDog(std::string name, int age, float price)
{
    Dog* dog = new Dog;
    dog->InitInfo(name); 
    dog->age   = age;
    dog->price = price;
    return dog;
}

// 444 工厂类 负责创建和销毁对象 注意业务还是写死的
template <class T>
struct ClassHolder
{
    int num = 0;
    std::map<std::string, T*> classes;
    void add(std::string& name, int age, float price)
    {
        T* newClass = new T;       
        newClass->InitInfo(name); 
        newClass->age   = age;
        newClass->price = price;  
        classes.emplace(name, newClass);    
        num += 1; 
    }

    void out(const char* name)
    {
        T * c = classes[name];
        std::cout<<"name  : " << c->m_info.name <<std::endl;
        std::cout<<"age   : " <<*((int*  )(c->m_info.member["age"  ].memberAddress)) <<std::endl;
        std::cout<<"price : " <<*((float*)(c->m_info.member["price"].memberAddress)) <<std::endl<<std::endl;
    }

    void outAll()
    {
        for(auto i:classes)
            out(i.first.c_str());
    }

    void holdNumber()
    {
        std::cout<< num<< " : instance hold" <<std::endl;
    }

    void save(const char* filename)
    {
        for(auto i: classes)
        {
            std::ofstream file(filename, std::ios::app);
            std::string name = i.first;
            T* c = i.second;

        //todo 写死得变量序列化
            int     age = *((int*  )(c->m_info.member["age"  ].memberAddress));
            float price = *((float*)(c->m_info.member["price"].memberAddress));
            file<< name <<" "<< age <<" "<< price  << std::endl;; //用空格作为人名分割

            std::cout << "saved:  " <<  name << std::endl;
        }     
    }

    void load(const char* filename)
    {
        std::ifstream file(filename, std::ios::in);
        std::string name;
        
        //todo 写死得变量反序列化
        int age; 
        float price;
        std::string line;

          
        std::cout<<"-------------------------------loading------------------------------"<<std::endl;
        while( std::getline(file, line)) 
        {
            std::istringstream ss(line);
            ss >> name >> age >> price;
            std::cout<<"load : " << name <<" "<< age <<" "<< price << std::endl;
            add(name  ,age , price);
        } 
        std::cout<<"-------------------------------endload------------------------------"<<std::endl;
    }

    ~ClassHolder()
    {
        for(auto i : classes)
        {
            std::cout << i.first << ": deleted" << std::endl;
            delete i.second;
        }
    }

};

int main()
{
    ClassHolder<Dog> hoder ;
    //hoder.add("pipi"  , 2 , 11.3);
    //hoder.add("huahua", 3 , 44.4);
    //hoder.add("mamam" , 6 , 9.2 );



    //hoder.out("pipi"  );
    //hoder.out("huahua");
    //hoder.out("mamam" );

    //hoder.save("dog.txt");
    hoder.load("dog.txt");
    hoder.holdNumber();

    hoder.outAll();
    
    


}


