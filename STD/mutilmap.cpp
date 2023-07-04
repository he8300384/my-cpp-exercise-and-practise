#include<string>
#include<map>
#include<iostream>
using namespace std;

int main()
{
  multimap<string, int> mm; 

//插入后自动根据名称排序
  mm.insert(pair("he", 123));
  mm.insert(pair("he", 223));
  mm.insert(pair("cc", 3123));
  mm.insert(pair("cc", 323));
  mm.insert(pair("hq", 123));
  mm.insert(pair("he", 323));

  auto pp = mm.equal_range("he"); //查找he的数据 返回一个迭代器区间 这个区间全是记录he的数据

    //迭代器区间中所有值遍历
  for(auto p =pp.first; p!=pp.second;++p) 
    cout<< p->second <<endl;
}
