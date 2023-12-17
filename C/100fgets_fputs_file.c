#include<stdio.h>
#include<stdlib.h>

//几种读取文本格式文件的操作

int main()
{
    FILE* file = fopen("out/file.txt","w+");

    char strings[20] ="name: char age: 12\n";

    fputs(strings,file); //没有格式整理 效率高
    fprintf(file,"name: %s age: %d score: %.2f\n","adf", 12, 23.2);
    fprintf(file,"name: %s age: %d score: %.2f\n","ccc", 22, 11.3);
    fprintf(file,"name: %s age: %d score: %.2f\n","dsf", 44, 12.1);
    fclose(file);

    FILE* file2 = fopen("out/file.txt","r");
    char c;
    char buffer[1024];

    //逐字符读取到文件尾
    while((c = getc(file2)) != EOF) 
    {   
        //if(c != '\n') //可自定义针对单字符的处理  可实现解析json
           putchar(c);
    }

    puts("\n-------------------------------------------\n");
    
    //另一种逐行读取方式
    rewind(file2);//注意重置文件指针
    while(fgets(buffer,1024,file2) != NULL) //注意判定条件
        fputs(buffer,stdout);

    rewind(file2);//注意重置文件指针
    char name[24]; int age; float num; 

    puts("\n-------------------------------------------\n");
    //筛取数据的读取方式
    int status = 3;
    while( (fscanf(file2,"name: %s age: %d score: %f\n", name, &age, &num)) != -1 ) //注意判定条件
    {
        printf("name: %s age: %d score: %.2f     fscanf return statu: %d   \n" , name, age, num );
        printf("fileptr offset %d\n" , ftell(file2)); //文件指针偏移
    }
    fclose(file2);
}