#include<stdio.h>
#include<wchar.h>
#include<locale.h>

int main()
{
    wchar_t str[] = L"宽字符串";
    setlocale(LC_ALL, "Chs");
    wprintf(L"%ls %lc\n" ,str, str[1]);
}