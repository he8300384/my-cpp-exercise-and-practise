#include<iostream>
#include<vector>
#include<list> //双链表
using namespace std;

class people
{
    public:
    int num;
    string name;

    people(int n, string m):num(n),name(m){cout<<"调用构造函数\n";}
    ~people(){cout<<"调用析构函数\n";}
    people(const people& p):num(p.num),name(p.name){cout<<"调k拷贝构造函数\n";}
     
};

int main(){
    vector<int> vv{1, 2, 3, 4, 5, 6, 7, 8};
    //构造list
    list<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    list<int> v1  {1, 2, 3, 4, 5, 6, 7, 8};
    list<int> v2(v);
    list<int> v3(v2.begin(), v2.end()); //不可可随机的list 构造list
    list<int> v4(vv.begin()+2, vv.end()); //可随机的vector 构造list

    //字符可以随机构造string
    char str[]="hello world";
    string si(str + 1, str +5); 
    for(auto i:si)
        cout<<i;
    cout << endl;

    
    //反转
    v.reverse();
    for(auto i:v)
        cout<<i<<" ";
    cout << endl;
    //排序
    v.sort();
     for(auto i:v)
        cout<<i<<" ";
    cout << endl;

    v.merge(v2);
    for(auto i:v)
        cout<<i<<" ";
    cout << endl;

    //切割移动
    list<int> v8 = {1, 2, 3, 4, 5, 6, 7, 8};
    list<int> v9{1, 2, 3, 4, 5, 6, 7, 8};

    auto a = v8.begin(); a++;
    auto b = v8.end(); b--;
    v9.splice(v9.begin(), v8, a, b); //切割v8链表到另一个链表v9位置接上
     for(auto i:v8)
        cout<<i<<" ";
    cout << endl;
    for(auto i:v9)
        cout<<i<<" ";
    cout << endl;
 
    //删除对应内容

    v9.remove(2);
    for(auto i:v9)
        cout<<i<<" ";
    cout << endl;

    //删除相邻重复
    v9.unique();
    for(auto i:v9)
        cout<<i<<" ";
    cout << endl;
 
}