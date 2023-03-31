#include<stdio.h>
#include<iostream>
//#include<string.h>
#include<string>
#include<unordered_map>
#include<time.h>

using namespace std; 

struct a
{
    int num;
    string name;
};


int main()
{
    unordered_map<int, string> a;
    unordered_map<int, string> b({{1, "aa"}, {2, "bb"}, {3, "cc"}, {4, "dd"}, {5, "ee"}});

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

    //auto re =  b.emplace(11,"dad");// 可原地构造但是 有拷贝构造 需要分段构造才会消减拷贝构造 
    cout << b.bucket_count() << " " <<endl; //(int)b.bucket_size()<<endl;
    cout << b.load_factor()<<endl;    //装填因子 成员数量/桶数
    cout << b.max_load_factor()<<endl;//最大桶

    b.insert({{11, "aa"}, {33, "bb"}, {12, "cc"}, {13, "dd"}, {14, "ee"}});
    cout << b.bucket_count() << " " <<endl; //(int)b.bucket_size()<<endl;
    cout << b.load_factor()<<endl;    //装填因子 成员数量/桶数
    cout << b.max_load_factor()<<endl;//最大桶

    cout<<"开始创建哈希表："<<time(0)   <<endl;
    //float t = time(0);
    unordered_map<int, string> m(10000000);//定义桶数量的构造
    for(int i =0; i< 10000000;i++) //创建时间业务暂停是很好不好的
    {
        //m.insert({i,"零时内容"});//慢 
        m.emplace(i,"零时内容");//快
    }
    cout<<"完成创建哈希表 耗时"<< time(0)  <<endl;


}