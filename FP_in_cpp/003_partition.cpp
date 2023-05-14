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
    string sex;
    Pepole(string n, int a, string s):name(n),age(a),sex(s){}
};

template<typename T>
bool is_man(T &a)
{
    cout << "开始过滤\n\n";
    if(a.sex == "man") return true;
    else return false;
} 

int main()
{
    //准备些实例用
    Pepole p1("add", 12, "man");
    Pepole p2("xxd", 22, "woman");
    Pepole p3("cdc", 11, "man");
    Pepole p4("acd", 32, "woman");
    Pepole p5("ddd", 42, "woman");

    //准备些 容器 
    vector<Pepole> pepoles={p1, p2, p3, p4, p5};
    vector<Pepole> pick_pepoles ={};
    vector<string> pepoles_names={};

    //重排列表 stable_partition 不会改变元素顺序
    auto it = partition(pepoles.begin(), pepoles.end(), is_man<Pepole>);

    //此时man排到前面了 找出man 
    pepoles.erase(it, pepoles.end());

    //查看
    for(auto i: pepoles) 
    cout<< i.name <<endl;
        
}