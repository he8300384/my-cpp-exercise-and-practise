#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
[]          空
[&]         全以引用捕获
[=]         全以值捕获
[this]      值防止捕获this指针
[&,a]       除a  全以引用捕获
[=,&b]      除a引用 其余值捕获
 */
int main(){
    vector<int> v{1,2,3,4,5};

    for_each(v.begin(), v.end(), [](const int & no){cout<<no<<"\n";});//用仿函数写回调函数

    auto f = [](const int & no){cout<<no<<"\n";}; //可以用名字

    for_each(v.begin(), v.end(),f);

    int aa = 3;
    int cc = 4;

    auto f2 = [aa, cc](const int & no){cout<<no<<" "<< aa << " "<< cc <<"\n";};
    f(2);

    auto f2 = [=](const int & no){cout<<no<<" "<< aa << " "<< cc <<"\n";};// = 自动捕获
    f(2);
}