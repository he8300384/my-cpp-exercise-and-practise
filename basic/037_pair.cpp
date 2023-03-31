#include<stdio.h>
#include<iostream>
//#include<string.h>
#include<string>

using namespace std; 

struct a
{
    int num;
    string name;
};


int main()
{
    pair<int,string> p0(1 , "aaaaaa");
    cout << p0.first <<" "<<p0.second <<endl;

    pair<int,a> p0(1 , a());//可以是类
}