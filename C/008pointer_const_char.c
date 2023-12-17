#include<stdio.h>

//字面常量总是单独存在一个空间中 所有操作需要通过其首地址指针

int main()
{
    const char* y;//内容不能被修改 指向可以改  不同字面量是不同的地址
    y = "sdf";
    y = "adfadf";

    const char* const z = "sdfaf"; //z不能被改
    // z= "asdf"; //会报错
   
    printf("%s \n", y);
    printf("%s \n", "asdfaf" + 1); //字面常量运算 实际操作了指针
    printf("%s \n", "asdfaf" + 2);
}