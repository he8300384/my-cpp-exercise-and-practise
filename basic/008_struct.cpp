#define _CRT_SECURE_NO_WARNINGS //不跳出c函数 安全警告
#include<iostream>
#include<string.h>

using namespace std;

struct pet
{
    char name[20];
    char type[20];
};

struct p
{
    int age;
    char name[20] = "aaa";//可以有默认值
    int money;
    pet p;
}p1{10,"ccc",12,{"aa","bb"}}; //这样可以初始化



void out(const p* ptr) //可以让参数无法被修改
{
    cout<<"函数输出结构体信息: "; 
    cout<<ptr->age <<"  " << (*ptr).money <<"  "<< ptr->name  <<"\n";//解引用
}

int main()
{    
    cout<<"结构体信息: ";  
    cout<<p1.age <<"  " << p1.money <<"  "<< p1.name  <<"\n";

    struct p p2={};//初始化为0
    cout<<"结构体信息: "; 
     cout<<p2.age <<"  " << p2.money <<"  "<< p2.name  <<"\n";

    p* ptr = &p1;
    cout<<"结构体信息: "; 
    cout<<ptr->age <<"  " << (*ptr).money <<"  "<< ptr->name  <<"\n";//解引用

    out(ptr);

    p* ptr2 = new p ();//堆创建结构体并初始化
    ptr2->age = 10;
    out(ptr2);
    memset(ptr2, 0, sizeof(p));//也可以这样初始化
    out(ptr2);
    delete ptr2;

    p p3[3];
    memset(p3, 0, sizeof(p3));
    // p3[0] = {12, "afc", 22};//c11
    // p3[1] = {13, "ffc", 12};//c11
    strcpy(p3[2].name, "aad");p3[2].age =11;p3[2].money = 100;

    for(int i; i < 3; i++)
    {
        out(&p3[i]);
    }

    p p4 = {12 , "aa", 22, {"ad","cc"}};
    cout << p4.p.name << p4.p.type <<endl;
}