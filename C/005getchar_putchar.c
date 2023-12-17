#include <stdio.h>
#include<ctype.h> //isalpha 

int main()
{
    char c;
    //c = getchar();
    // putchar(c);

    while((c=getchar()) != '\n')
        if(isalpha(c))//如果为文字
            putchar(c+1);  //读取一段文字并改变其ascall码
        else
            putchar(c);
    return 0;
}