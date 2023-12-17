#include<stdio.h>

//测试输入字符长度

int main()
{
    char string[256]  ;

    printf("in put a string:\n");
    scanf("%s", string);
    int len = 0;

    char* ptr= string;
    while( *ptr++ != '\0') //注意字符串结尾标志位是 0
        len +=1;

    printf("you in out string length is %d", len);
}