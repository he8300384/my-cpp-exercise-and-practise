#include<iostream>
#include<numeric>
#include<functional>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// 演示函数编程 折叠求值的思想   
 
 bool not_space(char s)
 {
    if(s == ' ') return false ;
    else return true; 
 }

//删除前空格 
string trim_left(string s)
{
    s.erase(s.begin(), 
            find_if(s.begin(), s.end(), not_space)
            );
    return s ;       
}

//删除后空格
string trim_right(string s)
{
      
    s.erase(find_if(s.rbegin(), s.rend(),not_space).base(),
            s.end()
            );
    return s ;       
}

//组合起来 实现前后空格删除
string trim(string s)
{
    return trim_left(trim_right(move(s)));//
}
 

int main()
{

    vector<int> num = {1,2,3,4,5,6};
    //标准库的 累加函数 是一个折叠求值的例子 注意给初始值用于计算
    int result = accumulate(num.begin(), num.end(), 0);

    cout << result <<endl;

    //
    string a = "    sdfasdf   ";

    cout << trim_left(a) << endl;
        
}