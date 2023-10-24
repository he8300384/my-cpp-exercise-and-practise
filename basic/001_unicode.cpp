#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#include<string.h>
#include<iostream>

using namespace std;

//宽窄字符区别和

int main()
{
    wchar_t str[] = L"宽字符串";
    setlocale(LC_ALL, "Chs");
    wprintf(L"%ls %lc\n" ,str, str[1]);


    const char* p_a = "123";
	int len = strlen(p_a); //窄字节长度
	cout << len << endl; 

	const wchar_t* p_w = L"123";
	int w_len = wcslen(p_w); //宽字节字节长度
    cout << w_len << endl;
}