#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;


//演示了基于流的文件读写
//二进制 read write 文件读写操作则 是有指针偏移的文件读写

struct pepole
{
   int age;
   string name;
   pepole(int a, string n):age(a), name(n){} 
};

 void save(pepole & p)
 {
   ofstream file("people.he", ios::app | ios::binary);
   int age = p.age;
   string name = p.name;
   file << age << name << " "; //用空格作为人名分割
   cout << "saved:  " << p.name << endl;
 }

 void load(vector<pepole>& pepoles)
 {
    ifstream file("people.he", ios::in| ios::binary);
    int age; string name;
    while(file >> age >> name) //空格作为输入流分段 每次循环读取空格间的一组数据
    {
        pepoles.push_back(pepole{age,name});
         cout << "loaded:  " <<  name << endl;
    }
 }


void read_file(string& buffer, string file_name)
{
    ifstream file(file_name, ios::in | ios::binary);
    file.unsetf(ios::skipws); //不忽略空格回车
    if(!file.is_open()) return;
    char s;
    while (file >> s) //逐个读取
    {
       buffer.push_back(s);
    }
    
    //while(!file.eof())
     //   buffer.push_back(file.get());
    file  >> buffer;
    cout << "copyed file\n";
    file.close();
}

void write_file(string& buffer, string file_name)
{
    ofstream file(file_name, ios::out | ios::binary);
    if(!file.is_open()) return;
    for(auto i: buffer)
        file << i;
     
    cout << "changed file\n"; 
    file.close();
}

int main()
{
    string buffer;
    read_file(buffer, "test.txt");
    cout << buffer << endl;
    write_file(buffer,"test_out.txt");

    pepole p1(12 , "aa");
    pepole p2(13 , "bb");
    pepole p3(14 , "cc");

    save(p1);
    save(p2);
    save(p3);

    vector<pepole> ps;

    load(ps);

    for(auto i: ps)
        cout<< "存档里有" << i.name  << endl;
}