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

int sort(const void* p1, const void* p2) //传入回调函数 注意指针类型转换 解引用
{
	// if(*((int*)p1) > *((int*)p2)) return 1;
    // if(*((int*)p1) < *((int*)p2)) return -1;
	// else return 0;  
    return *((int*)p1) - *((int*)p2);   
}

int main()
{
    int a[8] = {1, 3, 2, 4, 2, 5, 7, 6};
    qsort(a, sizeof(a)/sizeof(int), sizeof(int), sort);
    arrayOut(a, 8);
    cout<<"排序完毕" <<"\n";
}
    
