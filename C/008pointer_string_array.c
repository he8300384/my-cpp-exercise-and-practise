#include<stdio.h> 
 
int main()
{
    //指针数组定义  注意 const char* 和 char const* 
    const char * strings[ ] = {"content 1" , "content 2" ,"content 3" ,NULL}; //字面常量指针存储 必须使用 char const *

    //在定义一个以存指针 
    const char* strings_ptr[5];

    strings_ptr[0] = "content 1";
    strings_ptr[1] = "content 2";
    strings_ptr[2] = "content 3";
    strings_ptr[3] = "content 4";
    strings_ptr[4] = NULL;

    //读取内容 先定义一个 指向数组头的指针 两个 ** 含义是难点 
    const char ** ptr = strings_ptr ; //！  注意两次指向 第一次是指向 数组第几个内容 第二次指向const字面量

    printf("指针大小 = %d\n", sizeof(ptr));
     
    while(  *ptr != NULL) //以null作为结束判断 或者计算数组长度以结束
    {
        printf("%s\n", *ptr);
        ptr++;
    }
    return 0;
}