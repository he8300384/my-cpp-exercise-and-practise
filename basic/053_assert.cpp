#include<assert.h>
#include<iostream>

using namespace std;

void copydata(void* ptr1, void* ptr2){
    assert(ptr1&&ptr2);         //使用断言 断言失败调用abroad终止
    static_assert(  0 ,"有空指针"); //第一个参数是0会跳出编译 显示提示信息  编译器断言
    cout<<"复制数据......\n";
}

int main()
{
    int i = 0, j=0;
    copydata(nullptr , &j);//测试断言
}