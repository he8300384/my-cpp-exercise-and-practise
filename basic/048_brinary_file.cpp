#include<iostream>
#include<fstream>
 
using namespace std;

struct p
{
    int age;
    char name[20] = "aaa"; 
    int money;    
} ;

template<typename T>
void show(T & ptr)
{
    cout << "内容：" <<ptr.age  <<" " << ptr.name <<" "  <<ptr.money <<endl;
}

int main(){

    p p1{10,"ccc",12};
    p p2{20,"cad",22};
    p p3{11,"aaa",44};
    
    ofstream fout;
    fout.open("test02.dat",ios::app | ios::binary);// 写入模式 打开二进制文件

    fout.write((const char*)&p1, sizeof(p)); //使用write 函数写二进制  参数是(const char*) 需要转换 指针类型
    fout.write((const char*)&p2, sizeof(p));
    fout.write((const char*)&p3, sizeof(p));

    fout.close();
    cout << "文件写入完成\n";

    //读取二进制
     cout << "开始读取 ...\n";
    ifstream fin;
    fin.open("test02.dat",ios::in | ios::binary);
    if( fin.is_open() == false) //判断打开失败与否
    {
        cout<<"打开文件失败\n";
        return 0;
    }

    p p4;
    fin.read((char*)&p4, sizeof(p)); //单块读取
    show(p4);

    while(fin.read((char*)&p4, sizeof(p)))//全部读取
    {
        show(p4);
    }

    fin.close();
    cout<<"文件操作完成\n";
   
}