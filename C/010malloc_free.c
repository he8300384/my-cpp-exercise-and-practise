#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{   
    const int size = 10;
    //111申请空间 
    double* ptd = (double *)malloc(size * sizeof(double));

    //222通过下标操作符 访问申请的的空间
    for(int i = 0; i < size; i++)
    {
        ptd[i]  = i;
        printf("address: %u   \tvalue: %f \n",&ptd[i] , ptd[i]); //打印地址
    }
    
    //333释放空间
    free(ptd);

    // calloc calloc calloc calloc calloc

    char* ptd2 = (char *)calloc(12,sizeof(char)); //申请12字节空间

    const char* str = "abcdefg"; //随便搞个字符数组

    for(int i=0; i<12;i++) //无越界检查赋值
    {
        ptd2[i] = str[i];
        printf("address: %u\t value :%d \tASIIC:%c\n", &ptd2[i], ptd2[i], ptd2[i]);
    }
    //试着拷贝数据 和输出数据
    char  temp[10];
    strcpy(temp, ptd2);
    puts(temp);  
    printf("string : %s\n",ptd2);
    free(ptd2);

}