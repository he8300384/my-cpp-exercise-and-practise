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
	//int a[10] = {}; //所有元素初始化为0
	int a[10] = {11,12,31,13,12,123,11,1,33,11};//值初始化

	int b[10];

	memcpy(b ,a ,sizeof(a));//拷贝数组不能用 = 号 要用内存拷贝
	
	for(int i=0; i<(sizeof(a)/sizeof(int)); i++)
	{
		cout<< a[i] << ",";
	}
	cout<<endl;
	memset(a, 0, sizeof(a));
	for(int i=0; i<(sizeof(a)/sizeof(int)); i++)
	{
		cout<< a[i] << ",";
	}

	cout<<endl;
	for(int i=0; i<(sizeof(b)/sizeof(int)); i++)
	{
		
		cout<<"值: "<< b[i] << "\t";
		cout<<"地址: "<<(long long)(void*)(b + i)<<endl;//long long 才够长显示十进制地址值
	}
	

	
     cout<<"数组a地址值: "<< (long long)&a << "\n";

	 arrayOut(b, 10);

	int*dd=new int[100];
	cout<<"堆地址："<<(long long)(void*)dd<<endl;
	delete[] dd;
	cout<<"野指针："<<(long long)(void*)dd<<endl;
	dd=nullptr;
	cout<<"指针归0："<<(long long)(void*)dd<<endl;
}