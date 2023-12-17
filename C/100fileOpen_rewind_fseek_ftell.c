#include <stdio.h>

 //EOF 文件尾部为 -1

//! 文件指针的操作
errno_t putstring(const char* filename)
{
    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, filename, "w+") ; 
    if(t != 0  )
         return t; //打开失败码

    //一次写一串char数据 
    fputs("1 heqin\n", pf);  
    fputs("2 何钦 \n", pf);  
    fputs("3 test \n", pf);  
    fputs("4 11111 \n ", pf);  //注意换行会导致文件结束在下一行

    fclose(pf);
    return 0;
}

//多字符读
errno_t getstring(const char* filename)
{

    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, filename, "r") ; 
    if(t != 0) return t; //打开失败码
    

     char str[256] = {0}; //用于存储字符串


    fgets(str, 20, pf);  //一次读最多10个char 存储到str
    long position = ftell(pf); //! 查看文件指针位置
    printf("%s pf at : %d \n", str, position);      
    
    fseek(pf, 10, SEEK_SET);//!往后移动文件指针 SEEK_SET  SEEK_END SEEK_CUR

    fgets(str, 20, pf);  //一次读最多10个char 存储到str
    position = ftell(pf); //! 查看文件指针位置
    printf("%s pf at : %d \n", str, position);      

    fclose(pf);
    return 0;
}

int main(){
    putstring("out/test.txt");//写文件
    getstring("out/test.txt");//读文件
    return 0;
}