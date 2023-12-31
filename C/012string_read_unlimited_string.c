#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//不限制长度字符串读取

char * stringRead()
{
    char  buffer[10];  //零时区块大小 这里设的小以测验  
    size_t length = 0;
    char* str = NULL;

    while (scanf("%9[^\n]",buffer) == 1) //scanf 每次10个char的 从流中取字符到 buffer  注意 9 的用意 否则越界
    {
        size_t tempLength = strlen(buffer);
        char* old = str;

        str = (char *)realloc(str, length + tempLength + 1); // 分配更多的内存  

        if(str == NULL && old != NULL)
        {
            free(old);
            printf("fail to malloc\n");
            
            return NULL;
        }

        strcpy(str+length, buffer); //至多9个char 复制小段到内存中 10位置的结束符 0 被裁掉
        length += tempLength;
    }

    return str;
}

int main()
{
    char * ptr = stringRead();

    printf("%s",  ptr);

    free(ptr);
}