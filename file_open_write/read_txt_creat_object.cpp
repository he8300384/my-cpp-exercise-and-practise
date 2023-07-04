#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//从txt文件读取信息生成对象  对象存储到txt
//此技术可用于简单的序列化 反序列化

//测试类 
struct Test{
    string label;
    int val;
    vector<int> seq;
    bool res  ;
};

//字符操作 输入输出 覆写
std::ostream& operator<<(std::ostream& os, const Test& t) {
    os << t.label << " " << t.val << " ";
    for (int i : t.seq) {
        os << i << " ";
    }
    os << t.res;
    os <<'\n';
    return os;
}

std::istream& operator>>(std::istream& is, Test& t) {
    is >> t.label >> t.val;
     
    for (int i = 0; i < t.val; ++i) {
        int temp;
        is >> temp;
        t.seq.push_back(temp);
    }
    is >> t.res;
    return is;
}

int main() {

    vector<Test> TT;

    ifstream s2("test object.txt"); //读取文件
    
    while(!s2.eof())
    {    
        string line;
        getline(s2, line);
        stringstream sss(line);
         Test t2;
         sss >> t2;
         std::cout << "Parsed Test struct: " << t2.label << " " << t2.val << " ";
         for (int i : t2.seq) {
             std::cout << i << " ";
         }
         std::cout << t2.res << std::endl;
         TT.push_back(t2);
    }

    s2.close();

//对象序列 存储到 文件
    ofstream s3("test out object.txt", ios::app);

    for(auto i: TT)                  
        s3 << i;  
        
    s3.close();
    return 0;
}
 