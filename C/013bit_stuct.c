#include<stdio.h>
struct {
    unsigned int b1:1;
    unsigned int b2:1;
    unsigned int b3:1;
    unsigned int b4:1;
} bit;

int main()
{
    printf("%d",sizeof bit);
}
