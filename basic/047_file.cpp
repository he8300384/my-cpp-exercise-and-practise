#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*
ios::app	追加：输出将始终发生在文件的末尾
ios::ate	最后：输出最初在文件的末尾进行
ios::binary	二进制：读取或写入文件的数据是二进制形式的
ios::in	    输入：文件将允许输入操作。如果文件不存在，打开将失败
ios::out	输出：文件将允许输出操作。如果文件不存在，则创建一个给定名称的空文件
ios::trunc	截断：如果打开的文件存在，其内容将被丢弃，其大小被截断为零

二元或运算符 | 可以用来结合两个或更多标志的效果。例如，以下打开模式将导致打开的文件既可以输入也可以输出，并且输出最初在文件的末尾进行：

ios::in | ios::out 丨 ios::ate

以下是使用 fstream 打开 3 个文件执行输入、输出和输入输出的示例：

 
fstream inFile, outFile, inOutFile;
inFile.open("in.txt", ios::in);
outFile.open ("out.txt", ios::out);
outFile.open("inout.txt", ios::in | ios::out);
注意，使用 ios::out 标志会使现有文件的内容被删除，因为它假定程序员想要覆盖文件。如果 ios::out 与 ios::app 结合使用，则现有文件的内容将被保留，并且所有新数据都会附加到文件的末尾。

使用构造函数打开文件

ifstream、ofstream 和 fstream 这 3 个流类都有初始化构造函数，使用其中的一个初始化构造函数即可在单个语句中创建流对象并打开一个文件：

fstream outFile("inout.txt", ios::in | ios::out);
*/

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
    fout4 << "测试内容11\n";
     fout4 << "测试内容12\n";
      fout4 << "测试内容13\n";

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
    {cout<< buffer2 <<"完毕"<<endl;}
    fin.close();
   
}