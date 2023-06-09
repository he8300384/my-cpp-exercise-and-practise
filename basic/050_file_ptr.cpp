#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream fout;
    fout.open("test01.txt");//支持string R"()"

    fout << "测试内容1\n";
    fout << "测试内容2\n";
    fout << "测试内容3\n";
    fout << "测试内容3\n";

    fout.close();


    ofstream fout2("test01.txt",ios::out); //覆盖打开
    ofstream fout3("test01.txt",ios::trunc ); //覆盖打开

    fout2 << "测试内容1\n";
    fout2.close();
    fout3.close();

    ofstream fout4("test01.txt",ios::app ); //追加打开
    cout <<"文件指针位置："<< fout4.tellp()<<endl;
    fout4 << "测试内容11\n";
    cout <<"文件指针位置：" << fout4.tellp()<<endl;
     fout4 << "测试内容12\n";
     cout <<"文件指针位置：" << fout4.tellp()<<endl;
      fout4 << "测试内容13\n";
      cout <<"文件指针位置：" << fout4.tellp()<<endl;

    cout << "文件写入操作完毕\n";
    fout4.close();

    //输入流
    cout << "文件读取\n";
    ifstream fin;                                              
    fin.open("test01.txt",ios::in);
    //1 一行一行读
    string buffer;
    while(getline(fin, buffer)) //逐行读取
        {cout<< buffer <<endl;}
    fin.close();

         //2 简写 >>
    fin.open("test01.txt",ios::in);
    string buffer3;
    while( fin >> buffer3) //逐行读取
        {cout<< buffer3 <<endl;}
    fin.close();

    //3 固定缓冲大小
    fin.open("test01.txt",ios::in);
    char buffer2[101]; //c字符串
    while(fin.getline(buffer2,100))
    {cout<< buffer2 <<"完毕"<<endl;
     cout <<"文件指针位置：" <<fin.tellg()<<endl;   }
    fin.close();
     

    //随机读 
    fin.open("test01.txt",ios::in);
    fin.seekg(11);
    fin.getline(buffer2,100);
   while(fin.getline(buffer2,100))
    {cout<< buffer2 <<"完毕"<<endl;
     cout <<" 位置：" <<fin.tellg()<<endl;   }
    fin.close();

    //随机写
    fout.open("test01.txt",ios::in);
    fout.seekp(11);
    fout << "测试写入"; //乱写个位置会截断字符编码 覆盖换行符 输出异常
    fout.close();
}