#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//任意带有<< 运算的字符串转化
template<typename T>std::string to_string(const T& t)
{
    std::ostringstream os;
    os << t;
    return os.str();
} 

template<typename T>T from_string(const std::string&s)
{
   std::istringstream is {s};
   T t;
   if(!(is>>t)) 
    std::cout << "bad cast from string\n";
    return t;
}

//将一堆任意类型数据生成 格式化长字符串
string some_info_to_string(int a, int b, string &s)
{
    ostringstream os;
    os << a <<" "<<  b <<" "<<s<< " | "; //可以生成自己喜欢的字符格式
    return os.str();
}

int main(){
   
   std::string s1 = to_string(12.331);
   std::cout<< s1 <<std::endl;

   double d= from_string<double>("a23.12");
   std::cout<< d*2 <<std::endl;
   
   for(int i = 0; i<10; ++i)
   { 
     for(int j= 0; j<10; ++j)
    { 
        string s= "test";
        cout << some_info_to_string (i, j, s); //
    }
    cout <<endl;
   }
    
   
}