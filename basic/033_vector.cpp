#include <vector>
#include <iostream>

using namespace std;

class pepole{
    public:
    int age;
    string name;
    pepole(int a, string n ):age(a), name(n){}
};

template<typename T>
void info(vector<T> &v){
    cout << "容器capacity: " << v.capacity() <<" 容器size: " << v.size() << endl;
}

template<typename T>
void show(vector<T> &v){
    cout << "vector容器内容:  ";
    for(int i=0; i<v.size(); i++)
    cout << v[i] << " ";
    cout << endl;
}

template<>
void show(vector<pepole> &v){
    cout << "vector容器内容:  ";
    for(int i=0; i<v.size(); i++)
    cout <<"年龄: "<< v[i].age <<" 名字： "<< v[i].name << "    ";
    cout << endl;
}


int main()
{
    //几种常用构造
    vector<int> v0;
    info(v0);

    vector<int> v2(10);
    info(v2);

    for(auto i:v2) cout << i <<endl;

    vector<int> v4({1,2,3,4,5});

    //首地址
    cout<< "vector首地址: \t"<< v2.data() <<endl;
    cout<< "vector首地址: \t"<< v4.data() <<endl;
    
    //下标和指针方式修改值
    show(v4);
    v4[2] = 5;
    *(v4.data()+3) = 7;
    show(v4);

    //赋值
    cout<<endl;
    v0 = v4;
    show(v4);
    v2.assign({1,3,3,4,5});
    show(v2);

    //插入
    v2.push_back(8);     
    v2.push_back(9);
    show(v2);

    v2.emplace_back(9);//进化版push back 可原地构造 减少复制构造
    vector<pepole> p;
    p.emplace_back(12, "aa");//原地构造
    p.emplace_back(22, "bb");//原地构造
    show(p);

    //嵌套
    vector<vector<int>> vv;
    vector<int> v;

    v ={1,2,3,4,5};
    vv.push_back(v);

    v ={1,2};
    vv.push_back(v);

    v ={1,2,3,4,5,6,7};
    vv.push_back(v);

    for(int i =0; i<vv.size(); i++)//显示二维vector
    {
        for(int j = 0; j<vv[i].size(); j++)
        {
            cout << vv[i][j] <<" ";
        }
        cout<< endl;
    }
}