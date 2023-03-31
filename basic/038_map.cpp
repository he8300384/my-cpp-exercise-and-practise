#include<stdio.h>
#include<iostream>
//#include<string.h>
#include<string>
#include<map>

using namespace std; 

struct a
{
    int num;
    string name;
};


int main()
{
     map<int, string> a;
     map<int, string> b({{1, "aa"}, {2, "bb"}, {3, "cc"}, {4, "dd"}, {5, "ee"}});

    //map 是有序二叉排序树
     for(auto i: b)
        cout << i.first <<":"<<i.second << "   ";
     cout << endl;

    //插入
     b.insert({{9,"ad"},{11, "asd"}});//多个元素插入 插入失败也不会报错
     for(auto i: b)
        cout << i.first <<":"<<i.second << "   ";
     cout << endl;

    auto re =  b.insert({1,"SF"});//返回一个键值对 迭代器 ：bool
    for(auto i: b)
        cout << i.first <<":"<<i.second << "   ";
     cout  <<"插入成功与否"<< re.second << endl;

    auto re =  b.emplace(11,"dad");// 可原地构造但是 有拷贝构造 需要分段构造才会消减拷贝构造
    

}