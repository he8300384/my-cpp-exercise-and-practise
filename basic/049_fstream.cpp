#include<iostream>
#include<fstream>
#include<string>
 
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

    fstream fout; //可代替ofstream
    fout.open("test03.txt", ios::app);//支持string R"()"

    fout << "测试内容1\n";
    fout << "测试内容2\n";
    fout << "测试内容3\n";

    fout.close();

    //输入流
    cout << "文件读取\n";
    fstream fin;  //可代替ifstream                                            
    fin.open("test03.txt",ios::in);
    //1 一行一行读
    string buffer;
    while(getline(fin, buffer)) //逐行读取
        {cout<< buffer <<endl;}
    fin.close();

   
}