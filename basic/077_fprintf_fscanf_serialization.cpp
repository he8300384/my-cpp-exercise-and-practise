#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//朴素序列化  注意c函数格式化需求 和 [^;] 表示过滤掉; 否则乱码

//随便搞个结构体实验
 typedef struct person //typedef 用于 main中 结构体使用可不带struct  C特性
{
    char name[20]  ;
    int age; 
    char gender;
} person;

int main()
{
    //实列化个结构体
    person p1  ;
    strcpy(p1.name, "aaaa"); p1.age = 33;  p1.gender = 'S';

    //搞个文件
    FILE *file;
    fopen_s(&file, "people.dat", "w+");
    if(file== NULL) return 1;

    //以字符形式！ 格式化后  写文件  读写注意空格为一个自动识别单元 读写格式要一致
    fprintf_s(file, "(%s; %d; %c)\n", p1.name , p1.age, p1.gender);

    person  p2;
    fseek(file, 0, SEEK_SET); //fseek is a function in C and C++ that is used to move the file pointer to a specific location in a file. It is defined in stdio.h.
    //[^,] 让中建的 逗号或者其余标点可被识别
    
    fscanf(file, "(%[^;]; %d; %c)", p2.name, &p2.age, &p2.gender); //注意取地址符号参数是地址  [^;] 不去读取 ;
    printf("(%s %d %c)", p2.name, p2.age, p2.gender);

    //fclose(file);
    return 0;
}

/*
The %[^,] is a format specifier used in the scanf family of functions in C and C++. It is used to read characters until a comma (,) is encountered.

Here's a breakdown:

- % is the format specifier introduction.
- [...] is a scanset character. It tells scanf to match a nonempty sequence of characters from the specified set.
- ^ inside the scanset [] is the complementing character. It tells scanf to match all characters that are not in the specified set.
- , is the character that scanf should not match.

So, %[^,] will read and store characters until it encounters a comma. This is useful for parsing comma-separated values.*/