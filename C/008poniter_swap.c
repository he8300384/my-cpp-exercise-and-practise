#include<stdio.h>

//演示了指针的作用
//函数交换值要通过地址访问

void swap(int *a, int * b)//应当通过地址访问被操值
{
    int temp ;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int a,int b) //这是一个错误示范 
{
    int temp;
    temp= a;
    a = b;
    b= temp;
}
int main()
{
    int a = 2;
    int b = 3;
    printf("现在值 a = %d  b = %d\n", a , b);
    swap(&a,&b);//正确的
    printf("交换后 a = %d  b = %d\n", a , b);
    swap2(a,b);//错误 函数内部交换不起作用
    printf("交换后 a = %d  b = %d\n", a , b);
}