#include<iostream>
#include<string.h>

using namespace std;

union udata
{
    char ch[20];
    int  num;
    double dou;
};

struct st
{
    int a;
    union //匿名共同体在结构体内
    {
       char name[20];
       int na;
       double nb;
    };
    
};

int main()
{
    udata da;

    cout<<sizeof(da)<<endl;//大小会有对齐
    
    cout<< (long long)&(da.ch)<<"  " <<(long long)&(da.num)<<"  " <<(long long)&(da.dou)<< endl;//成员公用一段内存
     
}