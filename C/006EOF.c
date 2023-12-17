#include <stdio.h>
#include<ctype.h> //isalpha 

int main()
{
    char c;
    while ((c = getchar()) != EOF)  //ctrl + Z 是windows EOF    liunx Ctrl+D
    putchar(c);
    return 0;
}