#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool f(vector<int>& v, int i) //find 测试
{
    auto p =find(v.begin(), v.end(), i);
    if(p != v.end())
    {
     cout << "find\n"; 
     return true; 
    }              
    else  
    {
        cout << "not find\n"; 
        return false; 
    }              
}

class larger_than //用于find_if 的谓词
{ 
    int m_i; 
    public:
    larger_than(int i):m_i(i){};
    bool operator ()(int x)const {return x > m_i ;};  
};

bool f_if(vector<int>& v, int i)
{
    auto p = find_if(v.begin(), v.end(), larger_than(i) );//使用匿名对象 仿函数 也可使用lambda [&](auto a){return  a > i;}

    if(p != v.end())
    {
        cout << "find\n"; 
        return true; 
    }              
    else  
    {
        cout << "not find\n"; 
        return false; 
    }              
}

int main()
{
    vector<int> v1{1,2,4,5,7};
    f(v1, 2);
    f_if(v1 , 10);
    f_if(v1 , 5);
}