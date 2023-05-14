#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

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
    if(a.age > 20) return true;
    else return false;
} 


int main()
{
    Pepole p1("add", 12, 10);
    Pepole p2("xxd", 22, 20);
    Pepole p3("cdc", 11, 40);
    Pepole p4("acd", 32, 11);
    Pepole p5("ddd", 42, 30);
     
    vector<Pepole> pepoles={p1, p2, p3, p4, p5};
    vector<Pepole> pick_pepoles={};

    //transform 施加一个变化到序列元素 用一个新序列纪录新值 
    auto it = find_if(pepoles.begin(), pepoles.end(), age_old<Pepole>);

    cout << (*it).name << endl;
    

    
    
    
}