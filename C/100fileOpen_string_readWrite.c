#include <stdio.h>

 //EOF 文件尾部为 -1

//字符串符写
errno_t putstring(const char* filename)
{
    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, "test.txt", "w+") ; 
    if(t != 0  )
         return t; //打开失败码

    //一次写一串char数据 
    fputs("heqin\n", pf);  
    fputs("何钦\n", pf);  
    fputs("test\n", pf);  
    fputs("11111\n ", pf);  //注意换行会导致文件结束在下一行

    fclose(pf);
    return 0;
}

//多字符读
errno_t getstring(const char* filename)
{

    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, "test.txt", "r") ; 
    if(t != 0) return t; //打开失败码
        

     char str[256] = {0}; //用于存储字符串

    while(fgets(str, 50, pf))   //一次读最多50个char 存储到str 读到文件EOF fget返回null
    {
           
        printf("%s", str);      
    }
    
  
    fclose(pf);
    return 0;
}

int main(){
    putstring("test.txt");//写文件
    getstring("text.txt");//读文件
    return 0;
}