#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//经常用于库 的字符串存储 函数

char * strdup(const char * string)
{
    char * newString = (char *)malloc(strlen(string)+1); //注意字符串末尾多一个结束符号

    if(newString != NULL)
        strcpy(newString, string);

    return newString;
}

char * scanInput()
{
    char *string;

    //while(string != '\n')
    //{
        string = (char *) malloc(sizeof(char));

        
        scanf("%s",string);
        
    //}
        
}

int main()
{
    char * string = strdup("abcdef");

    printf("%s", string);

    *(string + 1) = 'y';

    printf("%s", string);

    free(string);

     
     
}