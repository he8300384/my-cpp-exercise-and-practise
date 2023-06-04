#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
    map<char, int> word;

    string s{"fsasdfssaga"};

    cout << "统计 "<< s << "字符量\n";

    for(auto w:s) 
        ++ word[w]; //索引键值对 int 项 自增 以统计字符频率  优雅

    for(auto i: word)
        cout << i.first << " : "<< i.second <<endl;    
     

}