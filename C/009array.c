#include<stdio.h>

//实现了3种多维数组传递参数的方式

//1111111111111111111111函数处理任意大小多维数组 函数只能获得数组首地址 然后手动计算 c的唯二方式 还有使用可变数组 但是可变数组也不是随便变！
void printA(const int* array , int cow ,int row)
{
     //(*array)++; const 防止这样的 修改
    for(int i = 0;i < cow;i++)
        {
        printf("\n");
        //注意通过首地址 存粹的数值化计算 元素的位置 容易写错 c不检查越界计算错就灾难
        for(int j =0; j< row; j++)
            printf("%d排%d列元素为: %d    " ,i,j, *(array + i*row + j ));
        }
   
}

//2222222222222222222222多维数组传参奇怪方式 好处是下标可以直接调用
void pring2A(int array[][3],int cow)
{
    for(int i=0;i<cow;i++)
    {
        printf("\n");
        for(int j=0;j<3;j++)
            printf("%d排%d列元素为: %d    " ,i,j, array[i][j] );//注意与上面的区别
    }
       
}

 
 //33333333333333333333333可变数组 编译后长度并不变 注意书写顺序必须严格 c99 vsc报错但能编译执行
void printAchangable(int cow, int row, int array[cow][row])
{
   for(int i=0;i<cow;i++)
   {
       printf("\n");
       for(int j=0;j<row;j++)
           printf("%d排%d列元素为: %d    " ,i,j, array[i][j] );//注意与上面的区别
   }
} 
 

int main()
{
    //只允许 初始化时这样赋值
    int myArray[5] = {1,2,3,4}; //其余没初始化的 编译器自动初始化为0
    int a[5] ;
    a[5]= 4  ; //错误 越界 不存在 5为下标的元素
    //a = myArray; //不允许 数组赋值
    int *b;
    b = myArray; //这样传递是正确的
    for(int i = 0; i < 5; i++)
        printf("第%d个元素值是： %d\n" , i ,b[i]);// b[i]意为地址偏移

    int twoDArray[2][3] = { {1,2,3},{2,3,4}};

    printA(&twoDArray[0][0],2,3); //直接使用数组名字也行 但有编译器警告数组和整数指针问题

    printf("\n值传递后打印******************* ");

    //意为 aa中存储了 大小为3的数组 
    int (*aa)[3]; //二维数组的声明方式 ()避免[]优先级在前

    aa = twoDArray;
    pring2A(aa,2);

    printf("\n可变参数数组函数打印******************* ");
    int twoDArray2[4][3] = { {1,2,3},{2,3,4},{3,4,5},{4,5,6}};
    printAchangable(4,3,twoDArray2);
    
    return 0;    
}