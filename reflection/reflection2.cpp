//一些实现反射的基础 宏 和函数

#include<iostream>
#include<string>

#define SHOWFUNC std::cout << __PRETTY_FUNCTION__<<'\n' ;

void info(int a)
{
    std::cout<<"File place   : "<<__FILE__<<std::endl;
    std::cout<<"Current line : "<<__LINE__<<std::endl;
    std::cout<<"Func         : "<<__func__<<std::endl;
    std::cout<<"Func detail  : "<< __PRETTY_FUNCTION__<<'\n' ; 
    //std::cout<<"Func detail  : "<< __FUNCSIG__<<'\n' ; // MSVC
}

void test()
{
    SHOWFUNC
}

class A
{
    public:
    int value;
    float age;

    void classtest()
    {
        SHOWFUNC
    }
};

int main()
{   
    info(1);

    const std::type_info& intInfo = typeid(int);
    const std::type_info& classInfo = typeid( A);

    std::cout << intInfo.hash_code() << std::endl;
    std::cout << intInfo.name() << std::endl;
     
     
    

    std::cout << classInfo.hash_code() << std::endl;
    std::cout << classInfo.name() << std::endl;
     
     
    
    test();

    A a;
    a.classtest();

    std::cout <<  offsetof(A , age) << std::endl;
}