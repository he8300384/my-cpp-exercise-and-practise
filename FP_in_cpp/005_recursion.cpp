#include<iostream>
#include<functional>
#include<string>

using namespace std;

//一个普通的递归函数
int recursion(int n)
{
    if      (n==0) return 1;
    else    return n * recursion(n-1);
}

//一个尾部递归
void tail_recursion(int n)
{   
    cout << n << endl;
    if      (n==0) return  ;
    else    return tail_recursion(n - 1);
}

//一个无需返回值的 过程递归 计算字符排列组合可能性
void doPermute(const string& chosen, const string& remaining)
{
    if(remaining == "") cout << chosen << endl;
    else 
        for(int u = 0; u < remaining.length(); ++u)
        doPermute(chosen + remaining[u], remaining.substr(0,u) + remaining.substr(u + 1));
}
void permute(const string &s){doPermute("", s);}

//

int main()
{    
     //for(int i = 1; i< 8; i++)
     //   cout << recursion(i) << endl;  

     tail_recursion(10) ;

     permute("abc");
     
     
     
   
}