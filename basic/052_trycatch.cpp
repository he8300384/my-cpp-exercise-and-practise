#define _CRT_SECURE_NO_WARNINGS //不跳出c函数 安全警告

#include<iostream>
#include<string.h>

using namespace std;


int main()
{
try
{
    int i=0;
    cout<<"输入 1-3 触发异常: ";
    cin >> i;
    if(i ==1) throw "输入了1";
    if(i ==2) throw i ;
    if(i ==3) throw string("输入了3");
    cout<<"没有 触发异常: ";
}
// catch(...)
// {
//     cout<<"捕捉全部异常\n";
// } 

catch(int i)
{
    cout<<"捕捉整形异常\n";
} 
catch(const char * c)
{
    cout<<"捕捉 chat* 异常 " << c << endl;
} 
catch(string s)
{
    cout<<"捕捉string异常 " << s <<endl;
} 
    cout<<"代码继承执行: ";  


    
}