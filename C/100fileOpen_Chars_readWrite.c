#include <stdio.h>

 //EOF 文件尾部为 -1

//单字符写
errno_t put(const char* filename)
{
    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, filename, "w+") ; 
    if(t != 0  )
         return t; //打开失败码

    //一次写一个char数据 
    fputc('a', pf);  

    fclose(pf);
    return 0;
}

//单字符读
errno_t getoneChar(const char* filename)
{

    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, filename, "r") ; 
    if(t != 0  )
         return t; //打开失败码

    char c = fgetc( pf);  //!一次读一个char数据

    printf("%c", c);
    fclose(pf);
    return 0;
}

//多字符读
errno_t getChars(const char* filename)
{

    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, filename, "r") ; 
    if(t != 0  )
         return t; //打开失败码
    char c;
    //遇到文件尾 结束循环
    while((c=fgetc( pf)) !=EOF) //!一次读一个char数据 且书上建议的处理方式
    {
         putchar(c);  //printf("%c", c); 一样效果

        //if(c == EOF)//方法1 遇到文件尾 结束循环
        //    break;

        //if(feof(pf))//方法2 遇到文件尾 结束循环
        //    break;   

    }
    
  
    fclose(pf);
    return 0;
}

int main(){
    //put(""out/test.txt");//写文件
    getChars("out/test.txt");//读文件
    return 0;
}