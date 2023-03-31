#include <vector>
#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int item;
    Node* next;
};

int* find1(int* arr, int n, const int& val) //无迭代器写法
{
    for(int i = 0; i < n; i++)
        if(arr[i] == val) return &arr[i];
    return nullptr;
}

int* find1(int* begin, int* end, const int& val)//数组中查找
{
    for(int* iter = begin; iter != end; iter++) //使用迭代器查找
        if(* iter == val) return iter;

    return nullptr;
}

Node* find1(Node* head, const Node& val) //链表中遍历查找
{
    for(Node * iter = head; iter != nullptr; iter= iter->next)//使用迭代器查找
    if(iter->item == val.item) return iter;
    return nullptr;
}

//模仿标准函数
template<typename T1, typename T2>
T1 find1(T1 begin, T1 end, const T2 &val)
{
    for(T1 iter= begin; iter!= end; iter++)
    if(*iter ==val) return iter;
    return end;
}

int main(){
 
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it = find1(v.begin(), v.end(), 3);
    if(it!= v.end())
        cout<<"查成功结果："<<*it << endl;
    else
        cout<<"查找失败\n";

    list<int> v2 = {1, 2, 3, 4, 5};
    list<int>::iterator it2 = find1(v2.begin(), v2.end(), 6);
    if(it2!= v2.end())
        cout<<"查成功结果："<<*it2 << endl;
    else
        cout<<"查找失败\n";

    //使用迭代器输出
    for(auto it = v2.cbegin(); it!=v2.end(); it++) //auto 替代 list<int>::const_iterator
        cout<< *it << " ";
    cout<<endl;

    //vector 区间取值构造
    vector<int> v3(v.begin()+2,v.end());
    for(auto it = v3.cbegin(); it!=v3.end(); it++) //auto 替代 list<int>::const_iterator
        cout<< *it << " ";
    cout<<endl;


    //vector 插入
    auto iter=v3.insert(v3.begin()+1 , 11);
    for(auto it = v3.cbegin(); it!=v3.end(); it++) //auto 替代 list<int>::const_iterator
        cout<< *it << " ";
    cout<<endl;


}