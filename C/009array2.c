#include<stdio.h>

int main()
{
    char  array1[] = "abcdefghi"; //这只是初始化数组语法糖 不是字面量

    char  array2[3][3] = {'a','b',0 ,'d','e', 0,'g','h', 0};  //二维数组实际也是一维存储的 0作为字符串结尾 

    char  array3[3][3] =    {{'a','b', 0},
                             {'d','e', 0},
                             {'g','h', 0}};  //写法更好理解 结果同上 

    for(int i = 0; i<3; i++)
        for(int j= 0; j<3; j++)
            printf("%c ", array2[i][j]);

    printf("\n%s\n", *(array2+1)); //注意指针运算的含义

    char (*p)[3] = array2; //指向每一行的指针声明
    printf("%s\n", p+2); //注意指针运算的含义
    
}