#include<iostream>
#include<string.h>

using namespace std;

int main()
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