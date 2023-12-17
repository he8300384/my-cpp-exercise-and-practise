#include<stdio.h>
#include<stdint.h>

 

int main()
{
    int i;
    printf("请输入2个整数\n");
    scanf("%*d %d", &i); //*跳过一个输入
    printf("你输入第二个数是：%d", i);
    return 0;
}