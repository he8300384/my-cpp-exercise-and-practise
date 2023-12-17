#include<stdio.h>
//#include<stdo

int main()
{
    puts("in put some string:\n");
    char bf[128];
    fgets(bf,128,stdin); //从流中读取定长数据 遇到换行符存储
    
    char cc[12] = {"sdaf"};
    puts(cc); //结尾加换行符

    char bf2[128];
    puts("in put some string:");
    //gets_s(bf2,127); gcc 编译器没有实现它 建议使用 fgets
    fputs(bf, stdout); //读到文件尾返回空指针
    puts("over");
    return 0;
}