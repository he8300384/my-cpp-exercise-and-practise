#include <stdio.h>
 
 
 //! 二进制模型式 

 struct Node
 {
    int a; 
    char str[20]; 
    double b;
 };

//字符串符写
errno_t putbinary(const char* filename)
{
    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, filename, "w") ; // r w  a追加模式   读写操作 r+  w+  a+
    if(t != 0  )
         return t; //打开失败码

    struct Node no1 = {312,"afqin", 12.3};//模拟一个实例 数组也行
    struct Node no2 = {412,"hfain", 22.3};//模拟一个实例 数组也行
    struct Node no3 = {152,"gagga", 32.3};//模拟一个实例 数组也行

    //这里分开写入慢 实际应该维护一个缓冲区 一并写入
    fwrite(&no1, sizeof(no1), 1, pf); //写二进制的长度  sizeof(no) * 1 
    fwrite(&no2, sizeof(no2), 1, pf); //写二进制的长度  sizeof(no) * 1
    fwrite(&no3, sizeof(no3), 1, pf); //写二进制的长度  sizeof(no) * 1
     
      //注意换行会导致文件结束在下一行
    
    fclose(pf);
    return 0;
}

//多字符读
errno_t getbinary(const char* filename)
{

    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, filename, "r") ; 
    if(t != 0) return t; //打开失败码
        
    int a;
    float b;
    struct Node no1;
      

    while(  !feof(pf)  ) // 一般维护一个缓冲区批量读取连续书数据这样访问硬盘效率低
    {
         

        fread (&no1, sizeof(no1), 1,pf);   //文件流读取数据到 结构体 字节长度至关重要
        printf("%d %f %s\n", no1.a ,no1.b ,no1.str);
        fread (&no1, sizeof(no1), 1,pf);  //文件流读取数据到 结构体
        printf("%d %f %s\n", no1.a ,no1.b ,no1.str);
        fread (&no1, sizeof(no1), 1,pf);  //文件流读取数据到 结构体
        printf("%d %f %s\n", no1.a ,no1.b ,no1.str);   
        fread (&no1, sizeof(no1), 1,pf);  

    }
    
    
    fclose(pf);
    return 0;
}

int main(){
    putbinary("out/test.b");//写文件
    getbinary("out/test.b");//读文件
    return 0;
}