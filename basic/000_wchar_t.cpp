#include <iostream>
#include <string.h>
 
using namespace std;
int main()
{
    wchar_t a[] = L"hello!"; //宽字占用空间翻倍
	cout << sizeof(a)<<endl;
    char *t = "aabc";
    wchar_t * p = L"hello!";
    cout<< strlen(t)<<endl;  //窄字 测字符数
    cout <<wcslen(p);        //宽字 测字符数
}
