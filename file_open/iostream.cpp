#include<iostream>

#include<sstream>

//测试字符流 输入输出流

using namespace std;
int main()
{
    ostringstream s;//常用于连接字符

    s <<  "aaa" <<  ":" << "bbb"; //存储一系列字符 

    s << " cccc";

    s.str(); //返回它自身的拷贝
    ostringstream ss;
    ss.str(s.str()); // 从s 拷贝
    
    cout << ss.str().c_str() << endl; //使用存储的字符

    istringstream s2 ;

    cout<< " 输入字符以 打印单字符\n";
      
    for(char c; cin.get(c);)
    {
        char upper = toupper(c) ; //大写转换 tolower 小写转换
        cout << upper << endl;
    }
       
       

}