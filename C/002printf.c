#include<stdio.h>
#include<stdint.h>

 

int main()
{
    int size;
    printf("整数:%d  浮点数:%f   字符:%c   字符串:%s\n", 1, 12.1, 'a', "dfa"); 
    printf("制表符 \t*%30s*\n", "和对齐方式");
    printf("制表符  *%-30s*\n",   "和对齐方式");
    
    printf("进制转换 %u\n",10);
    printf("进制转换 %x\n",10);
    printf("进制转换 %X\n",10);
    printf("进制转换 %o\n",10);

    printf("控制间隔%9d %9d %9d\n", 1123, 13, 141);
    printf("控制间隔%9d %9d %9d\n", 11 , 1313, 141);
    printf("控制间隔%9d %9d %9d\n", 1 , 131, 14131);

    for(int i=1;i<3;i++)
        printf("*的使用 %*d\n", i, 3);// *是一个值替换
     
    return 0;
}