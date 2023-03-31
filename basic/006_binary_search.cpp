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

 
 bool binary_search(int arr[], int length, int key)
 {
    int low = 0, high = length - 1, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(mid == key) return true;
        if(arr[mid] < key)  high  = mid -1;
        else low = mid + 1;
    }

 }

int main()
{
    int a[8] = {1, 3, 2, 4, 2, 5, 7, 6};
    
    int input ; 
    cout<<"输入一个整数寻找 :" <<"\n";
    cin >>input; 
    if(binary_search(a, 8 , input))
    {
        cout<<"找到" <<"\n"; return 0;
    }
    cout<<"没找到" <<"\n";
}
    
