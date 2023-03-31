#define _CRT_SECURE_NO_WARNINGS //不跳出c函数 安全警告
#include<iostream>
#include<string.h>

using namespace std;

 struct pepole
 {
    char name[20] ;
    int num;
    int money;
    string info;
 }p1;
 

int main()
{
    cout << "npos="<<string::npos<<endl; //string 容量

    string s1; //默认构造函数

    cout << s1 <<endl<< s1.capacity() <<endl<< s1.size() << endl; //输出内容 容量和 字节大小  
    cout << "内容首地址： "<< (void *)s1.c_str()<<endl;
    

    s1 = "hello world my frind";

    cout << s1 <<endl<< s1.capacity() <<endl<< s1.size() << endl; //输出内容 容量和 字节大小  
    cout << "内容首地址： "<< (void *)s1.c_str()<<endl; //扩容后地址改变

    //拷贝构造
    string s2 = s1; 

    //指定大小构造 可理解为指定大小内存分配 
    string s6("hello world",5);
    cout << "s6: " << s6 << " " << s6.capacity() <<" "<< s6.size() << endl;
    string s7("hello world",50);
    cout << "s7: " << s7 << " " << s7.capacity() <<" "<< s7.size() << endl; //显示会有乱码 容积扩大

    //截取构造
    string s8(s1 , 3, 5); 
    cout << "s8: " << s8 << " " << s8.capacity() <<" "<< s8.size() << endl;
    string s9(s1 , 3);//注意如果不是复制构造 会调用指定大小构造 而不是截取构造
    cout << "s9: " << s9 << " " << s9.capacity() <<" "<< s9.size() << endl;
     
    //创建指定大小的空容器
    string s10(8, 'x');
    cout << "s10: " << s10 << " " << s10.capacity() <<" "<< s10.size() << endl;

    //可以利用string 作为内存缓冲区

    //在string中存struct
    cout << "在string中存struct "<< endl<< endl;
    string buffer;
    cout << "sizeof string: "<< sizeof(buffer) <<" capacity: "<<buffer.capacity() <<" size: "<< buffer.size()<<endl;
    for(int i = 0; i < 10; i++) //存
    {
        memset(&p1, 0, sizeof(struct pepole));    //！会导致内存泄漏 测试程序没有计较不要实用
        p1.num = i;
        p1.money = i+10;
        sprintf(p1.name, "人员%02d", i);           //char成员需要这样赋值
        p1.info = "人类";
        buffer.append((char*)&p1,sizeof(pepole));  //追加数据
        //cout << "appended\n";
    }
    cout << "赋值后 "<<endl;
    cout << "sizeof string: "<< sizeof(buffer) <<" capacity: "<<buffer.capacity() <<" size: "<< buffer.size()<<endl;

    for(int i = 0; i < 10; i++) //存
    {
         memset(&p1, 0, sizeof(struct pepole));  //！会导致内存泄漏 测试程序没有计较不要实用
         memcpy(&p1, buffer.data()+i*sizeof(struct pepole),sizeof(struct pepole));
         cout << "序号:" << p1.num << "  姓名："<< p1.name << "  金钱："<< p1.money << "  备注："<< p1.info <<endl;
         
    }
}