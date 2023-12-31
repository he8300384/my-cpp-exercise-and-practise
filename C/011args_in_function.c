#include<stdio.h>
#include<stdarg.h>//可变参数宏的使用

//可变参数 无法识别参数的 1 数量 2类型

float averge(int n_values, ...)
{
    va_list va_arg;
    int count;
    float sum =0;

    va_start(va_arg, n_values);

    for(count=0; count < n_values; count ++)
    {
        sum +=va_arg(va_arg, int);
    }
    va_end(va_arg);

    return sum/n_values;
}

void print(int n_values, ...)
{
    va_list va_arg;             //固定前置宏
    va_start(va_arg, n_values); //固定前置宏

    for(int i; i<n_values; i++)
    {
        printf("%s", va_arg(va_arg, const char *));  //中间遍历参数列表
    }

    va_end(va_arg);             //固定后置宏
}


int main()
{
    printf("%f\n", averge(3, 11, 13, 14));

    print(3, "aaa", "bbb", "ccc");
}