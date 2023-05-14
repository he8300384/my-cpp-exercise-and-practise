#include<iostream>
#include<functional>
#include<string>
#include<windows.h>

using namespace std;
//演示用递归 替代while
void recursion(int n)
{   
    if(n < 100)
    {
   
        if(n % 10 == 0)
            cout << endl;
        else 
            cout << "数字：" << n << "  ";
        Sleep(400);
        recursion(n+1);    
    }
    else //一直显示直到 退出条件
    return;
}

int main()
    {
        recursion(0);
    }