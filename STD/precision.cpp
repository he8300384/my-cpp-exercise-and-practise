#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
    float vaule = 10;
    float x = 1.0/vaule; //! 截断错误  x永远不会是一个精确固定值 
    float sum =0;
    for(int i=0;i<vaule;++i) sum+=x;
    cout<<setprecision(15)<<sum <<endl;//并不得到 1 ！


    short int y = 40000;//! 溢出
    int i = 1000000;

    cout << y << " " << i*i <<endl;//! 溢出
}