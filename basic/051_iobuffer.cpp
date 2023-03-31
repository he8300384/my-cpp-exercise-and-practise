#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){

    string buffer;
    ifstream fin;
    fin.open("test01.txt", ios::in);
    if( fin.is_open()  == false) 
    {
        cout<< "文件不存在\n";
        return 0;
    }
   
    while(true)
    {
        fin>>buffer;
        cout<< "eof: " <<fin.eof() << " badbit: " << fin.bad() << 
        " failbit: "<< fin.fail() <<" good?: "<<fin.good() <<  endl;
        if(fin.eof()==true) break;//利用标志位 判断文件是否结束

        
        cout<<buffer<<endl;

    }
   
}