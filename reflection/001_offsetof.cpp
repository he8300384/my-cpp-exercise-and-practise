//实现反射的基础  获取成员变量固有偏移 和实例真实地址

#include<iostream>
#include<string>
#include<typeinfo>

class A
{
    public:
    int value;
    int* ptr = nullptr;
    std::string name;
    float age;

    A(int v, const char* n, float a):value(v),name(n),age(a){}

    A* Apointer()
    {
        return(this);
    }

    void info()
    {
        //这个typeid生成一堆 JB 名字也太抽象了
        std::cout<<typeid( value).name() << std::endl;
        std::cout<<typeid( ptr).name() << std::endl;
        std::cout<<typeid( name).name() << std::endl;
        std::cout<<typeid( age).name() << std::endl;
        std::cout<<typeid( *this).name() << std::endl;
    }

    //virtual ~A(){}
};

int main()
{   

    A a(12, "aaa", 23.4);
    A b(13, "bbb", 13.1);

    //类属性地址偏移可以计算得到
    std::cout << "menber offset :"<<  offsetof(A , value) << std::endl;
    std::cout << "menber offset :"<<  offsetof(A , ptr) << std::endl;
    std::cout << "menber offset :"<<  offsetof(A , name) << std::endl;
    std::cout << "menber offset :"<<  offsetof(A , age) << std::endl;

    //实例地址可以获取到
    A* Aptr = a.Apointer();

    //访问属性值 可利用实例地址加偏移量 访问 （我手抄了以上偏移量）
    std::cout << "instance value :"<<   *(  (int *)        ((char*)Aptr + 0 )  )  << std::endl;
    std::cout << "instance value :"<<   *(  (int *)        ((char*)Aptr + 8 )  )  << std::endl;
    std::cout << "instance value :"<<   *(  (std::string *)((char*)Aptr + 16)  )  << std::endl;
    std::cout << "instance value :"<<   *(  (float *)      ((char*)Aptr + 48)  )  << std::endl;


    b.info();

}