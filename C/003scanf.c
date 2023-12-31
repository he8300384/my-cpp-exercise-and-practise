#include<stdio.h>
#include<stdint.h>

void test()
{
    char * buffer[128];
    int c = 1;
    while( c < 10)
    {
        printf("读取成功否： %d\n", scanf("%4[^\n]", buffer)); //注意不用通用格式符 自定义每次从流中取多少 忽略什么
        printf("%s\n", buffer);
        c++;
    }
}

int main()
{
    int i;
    //printf("请输入2个整数\n");
    //scanf("%*d %d", &i); //*跳过一个输入
    //printf("你输入第二个数是：%d", i);

    
    
    
    
    char buffer[128];
    int c = 1;
    while( scanf("%4[^\n]", buffer) == 1) //读取失败返回 0 
    {
        
        printf("%s\n", buffer);
        c++;
    }
    
    
    
  
  
  
    return 0;
}