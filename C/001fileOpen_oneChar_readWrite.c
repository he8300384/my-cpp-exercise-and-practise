#include <stdio.h>

/*
    //! 老版本 没有打开成功检查
    FILE* file = fopen("test.txt", "w+"); // r 读 w 写 w+ 如无创建写
    fclose(file);//释放缓冲区

    //! 新版本打开
    FILE* pf = NULL;
    errno_t t =  fopen_s(&pf, "test.txt", "w+") ; //检查打开成功与否 0 成功 
    if(t == 0  )
        printf("read file success\n");
*/

errno_t put(const char* filename)
{
    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, "test.txt", "w+") ; 
    if(t != 0  )
         return t; //打开失败码

    //一次写一个char数据 
    fputc('a', pf);  

    fclose(pf);
    return 0;
}

errno_t get(const char* filename)
{

    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, "test.txt", "r") ; 
    if(t != 0  )
         return t; //打开失败码

    char c = fgetc( pf);  //一次读一个char数据 文件结尾返回-1

    printf("%c", c);
    fclose(pf);
    return 0;
}

int main(){
    put("test.txt");//写文件
    get("text.txt");//读文件
    return 0;
}