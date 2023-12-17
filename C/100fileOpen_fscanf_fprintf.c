#include <stdio.h>

 //! 注意scanf 从流中取数据的分块规则 %s 识别空格为结尾    %[^不想被识别的符号] 自定义结束识别符号

//字符串符写
errno_t putstring(const char* filename)
{
    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, "out/test.txt", "w+") ; // r w  a   读写操作 r+  w+  a+
    if(t != 0  )
         return t; //打开失败码

    //一次写一串带一定格式的数据 
    
    fprintf_s(pf,"time:%d, tem:%.2f, name:%s.\n", 12 ,3.12313,"he 句号用作字符接尾标志",20);  //安全版本需要指定输出字符串字节数
    fprintf_s(pf,"time:%d, tem:%.2f, name:%s.\n", 15 ,4.12313,"aw 用%s的话空格会被认为是一个字符的结束",20);  //.2 f 控制小数位
    fprintf_s(pf,"time:%d, tem:%.2f, name:%s.\n", 13 ,1.12313,"rw 现在 多少个 空格 都识别",20);  
      //注意换行会导致文件结束在下一行

    fclose(pf);
    return 0;
}

//多字符读
errno_t getstring(const char* filename)
{

    FILE* pf = NULL;
    //检查打开成功与否 0 成功 
    errno_t t =  fopen_s(&pf, "out/test.txt", "r") ; 
    if(t != 0) return t; //打开失败码
        
    int a;
    float b;
    char name1[60];
    char name2[60];
      

    while(  !feof(pf)  ) //最好这样写 因为换行可能导致 文件结束在空白行
    {
        //对于空格fscanf识别为的独立字符串
        //time 等字符匹配读到的内容 一致就会被抛弃
        //%特性符  %s读到空格之间的字符 加个结束位 塞给变量 
        //匹配是逐字符的 一旦有一个字符匹配失败整个匹配过程就中断
        fscanf (pf,"time:%d, tem:%f, name:%[^.].\n", &a ,&b,name1); //这里如果用%s去匹配 那么文字中建的空格就被识别了 所以[^.]定义 . 为结束位 
         //if(ferror) break; //没有这句 一旦格式化读取错误就死循环
        printf("%d %f %s\n", a ,b , name1 );      
    }
    
  
    fclose(pf);
    return 0;
}

int main(){
    putstring("test.txt");//写文件
    getstring("text.txt");//读文件
    return 0;
}