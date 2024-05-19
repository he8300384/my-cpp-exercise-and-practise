//自己写得一个固化反射 案例 
//难点在于支持各种类和 自动识别信息

#include<iostream>
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
    const char* name; //类名
    void* address;    //用于访问的地址
    void* father;     //父类
    std::map<std::string, class memberInfo> member; //成员变量 变量有各种类型 这里又得搞个结构体
};

// 111 我有个类c++需要自己额外申请空间记录 成员信息   MMP c++脑壳有病 
struct Dog
{
    int age;
    class classInfo m_info;//每个实例信息
    void InitInfo(const char* name);//填写类型信息 //todo 怎么保证生成一个实例自动注册信息呢
};

// 222 那么我们得填写以上信息 //todo 怎么保证自动填写呢 这里全是手动得 当然可以每一种情况定义一个函数重载 实际又得用模板
void Dog::InitInfo(const char* instanceName)
{
    m_info.name = instanceName;
    m_info.address = this;
    m_info.father = nullptr;
    m_info.member.emplace("age", memberInfo{"age", this + offsetof(Dog, age), 4});
}

// 333 可以使用工厂类或者 函数 创建实例
Dog* newDog(const char* name)
{
    Dog* dog = new Dog;
    dog->InitInfo(name); 
    dog->age = 10;
    return dog;
}

int main()
{
    //创建一个实例
    Dog* dog = newDog("wangcai");

    //通过名字查询属性
    std::cout<<"name :\t" << dog->m_info.name <<std::endl;
    std::cout<< "age :\t" <<*((int*)(dog->m_info.member["age"].memberAddress)) <<std::endl;

}


