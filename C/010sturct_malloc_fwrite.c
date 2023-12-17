#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 堆和文件 存取结构体数据

#define SIZE 3000

struct man
{
    int num;
    float age;
    char name[64]  ;
};

int main()
{
      //试着存入结构体
    struct man* mans=(struct man*)calloc(SIZE,sizeof(struct man));
    
    //随便填充一些结构数据
    for(int i=0; i<SIZE ;i++)
    {
        mans[i].num = i;
        mans[i].age = 12.0 + i;
        strcpy(mans[i].name ,"faf");  
        //让名字不一样
        mans[i].name[0] += i%20;  
        mans[i].name[1] += i%20;  
        mans[i].name[2] += i%20;  
    }

    //批量读取
    for(int i = 0; i<SIZE ; i ++)
        printf("number: %d \t age: %.2f \t  name: %s\n", mans[i].num, mans[i].age, mans[i].name);


    //写入文件
    FILE *file = fopen("out/struct.dat","wb+");
    fwrite(mans,sizeof(struct man),SIZE,file);

    fclose(file);

    free(mans);

    puts("\n---------now read struct data from file-----------\n");
    //从文件读取  

    struct man* mans2=(struct man*)calloc(SIZE,sizeof(struct man));
    FILE *file2 = fopen("out/struct.dat","rb");
    fread(mans2,sizeof(struct man),SIZE,file2);

    fclose(file2);

    for(int i = 0; i<SIZE; i ++)
        printf("number: %d \t age: %.2f \t  name: %s\n", mans2[i].num, mans2[i].age, mans2[i].name);

    free(mans2);
    
}