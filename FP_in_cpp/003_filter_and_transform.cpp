#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// 演示函数编程组合完成任务的思想  过滤 -> 变换  

class Pepole
{
    public:
    string name;
    int age;
    int money;
    Pepole(string n, int a, int m):name(n),age(a),money(m){}
};

template<typename T>
bool age_old(T &a)
{
    cout << "开始过滤\n\n";
    if(a.age > 20) return true;
    else return false;
} 

template<typename T>
string names(T &n)
{
    cout << "开始变换\n\n";
    return n.name;
} 


int main()
{
    //准备些实例用
    Pepole p1("add", 12, 10);
    Pepole p2("xxd", 22, 20);
    Pepole p3("cdc", 11, 40);
    Pepole p4("acd", 32, 11);
    Pepole p5("ddd", 42, 30);

    //准备些 容器 
    vector<Pepole> pepoles={p1, p2, p3, p4, p5};
    vector<Pepole> pick_pepoles ={};
    vector<string> pepoles_names={};

    //过滤 返回依然是 同类型列表
    copy_if(pepoles.begin(), pepoles.end(), back_inserter(pick_pepoles), age_old<Pepole>);
    //变换 列表类型变化了
    transform(pepoles.begin(), pepoles.end(),back_inserter(pepoles_names), names<Pepole>);

    //变换模型
    for( auto i : pepoles_names)
        cout << i << endl;
        
}