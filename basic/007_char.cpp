#define _CRT_SECURE_NO_WARNINGS //不跳出c函数 安全警告

#include<iostream>
#include<string.h>

using namespace std;

void arrayOut(int a[], int len) //必须传入数组长度 函数内部计算sizeof(a) 只会是 *int 4字节
{
	for(int i; i<len;i++)
	{
		cout << a[i] << "  ";
	}
	cout <<endl;
}

int main()
{
    char a[10] = "adffasd11";  
    char b[10] ={0}  ;      //初始化不要忘记
    strcpy(b,a);
    cout << b << endl;

    int c;
    //int lis[c]; //不能用常量

    char d[10] ={0}  ; 
    strncpy(d,a,3); //注意一旦有截取结尾0就消失 所以全员清0很必要
    cout << d << endl;
    
}