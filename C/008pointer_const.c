#include<stdio.h>

//   char * const 是地址不能变    const char*是内容不能变
//  指针数组 存储 常指针 会有点绕

int main()
{
    const char* a = "adsfadfa"; //注意字面量是const地址 
    
    //数组存储 a
    //数组内容是指针   且这个指针指向字面量指针 字面量指针自己不能变 所以 内容格式char const*
    const char * array[10]; 

    array[0] =a ;

    printf("array[0] 地址 %u\n", &array[0]);
    printf("array[0] 内容 %u\n",  array[0]);
    printf("字面量const地址 内容 %u\n", "adsfadfa");
    printf("array[0] 内容解引 %c\n",  *array[0]);
   
    int cc = 1;
    int * const bb  = &cc; //内容可变

    *bb =22;

    printf("%d\n", cc);
}