
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>


int main()
{   
    const char* c = "中文文字";
    printf("文字长度 ：   %d \n", strlen(c));
    printf("文字占空间 ： %d \n", sizeof("中文文字"));
    printf("%s", "中文");
    puts(c);

    wchar_t s[] = L"在中文";
    //scanf("%s", s);
    wprintf(L"%ls\n", s);
    getchar();
}