#include<iostream>
#include<vector>
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
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    for(auto i = v.begin()+3; i != v.end(); i++)
        cout << *i << " ";
    cout << endl;

    for(int i:v) //for 的范围循环写法1
        cout << i << " ";
    cout << endl; 

    for(auto i:{1, 2, 3, 4, 5, 6, 7, 8}) //for 的范围循环写法2
        cout << i << " ";
    cout << endl;

    //内容是类时要小心 多次拷贝构造
    vector<people> p;
    p.emplace_back(12, "aa");//原地构造
    p.emplace_back(11, "bb");// vector 的扩容会导致拷贝
    p.emplace_back(15, "cc");// vector 的扩容会导致拷贝

    for(auto ii: p)// ii非引用会导致拷贝 应当 &ii
        cout <<"姓名： "<< ii.name <<" 编号： "<< ii.num << endl;
}