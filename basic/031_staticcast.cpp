#include<iostream>
#include<string.h>

using namespace std;


class toy {};

class bull:public toy{ public: std::string name = "default";int price = 0;};
class cake:public toy{ public: std::string name = "default";int price = 0;};
class ball:public toy{ public: std::string name = "default";int price = 0;};

class factory
{ 
    public:
    static toy* make_toy(std::string s)
    {
         if(s == "bull") return new bull;
         if(s == "cake") return new cake;
         if(s == "ball") return new ball;
    }
};

void test_cast()
{
    toy* b1 = factory::make_toy("bull") ;
    bull* b2 = static_cast<bull*> (b1)  ; //父类指针向子类转换 才能访问子类属性
    std::cout<<b2->name;
}

void test_cast2()
{
    int i =10;
     double dd =1.31;
     long i2 =(long)dd;                     //c风格 可能丢失数据的隐式转换
     long i3 = static_cast<long>(dd);       //c++ 风格的转换

     double* pd = (double*)&i;              //c风格 可能丢失数据的隐式转换

     void* pv = &i;                         //c++ 风格的转换 1步  转换void*
     double* pd2=static_cast<double*>(pv);  //c++ 风格的转换 2步  void*到其他类型指针

     double* pd3=reinterpret_cast<double*>(&i);//直接转换指针
}

int main()
{
    

     test_cast();

     test_cast2();
}