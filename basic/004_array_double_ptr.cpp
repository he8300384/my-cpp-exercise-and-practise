#include<iostream>
#include<string >

using namespace std;
int main()
{   
    int * i1 = new int(1) ;
    int * i2 = new int(2) ;
    int * i3 = new int(3) ;
    
    int* list[3] = {i1, i2, i3};

    int ** ptr;

    ptr = &list[1];//指针指向数组节点 由于节点只是存储了地址 要到此地址去寻找内容

    cout <<"指向数组某个节点地址：" << ptr << endl; 
    cout <<"数组节点内存储的地址：" << *ptr << endl; 
    cout <<"双重指针最终指向内容：" << **ptr << endl; 

}