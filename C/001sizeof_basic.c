#include<stdio.h>
#include<stdint.h>

#define OUTPUT(type) printf("%-10s \t\t  size is : %d\n", #type, sizeof(type)); //  

//!输出基本类型 sizeof 长度

int main()
{
    int size;
    OUTPUT(int)
    OUTPUT(short)
    OUTPUT(long)
    OUTPUT(float)
    OUTPUT(double)
    OUTPUT(char)
    //OUTPUT(bool)
    OUTPUT(long long)
    OUTPUT(unsigned int)
    OUTPUT(int8_t)
    OUTPUT(int16_t)
    OUTPUT(int32_t)
    OUTPUT(int64_t)
    OUTPUT(intmax_t)
    
    

    return 0;
}