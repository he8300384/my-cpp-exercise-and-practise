   #include <vector>
#include <iostream>
#include <list>

using namespace std;

//为普通类赋予迭代器

struct mystruct
{
    vector<string> name{"aa","bb","cc","ee"};
    vector<int> num{0,1,2,3}; //这里数字用于上一个容器 手动下标访问 书写错误将越界 只做演示 

    //将成员 的迭代器赋予类 
    vector<int>::iterator begin(){return num.begin();}
    vector<int>::iterator end(){return num.end();}
};

int main()
{
    mystruct mm;
    
    // 迭代器 赋予普通类 将简化查询操作
    for(auto i:mm)
    {
        cout<< mm.name[i]<<endl;
    }

}
