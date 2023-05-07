#include<iostream>
#include<vector>
#include<functional>
#include<numeric>

using namespace std;

int main()
{
    vector<int> v1= {1, 2, 3, 4};
    
    //从左到右 折叠计算 总和
    auto foldl = accumulate(begin(v1), end(v1), 0,
         [](int &i, int &j){cout<<i<<"+"<<j<<endl; return i+j;});

    cout <<"= "<< foldl << endl;

     //从右到左 折叠计算 总和
    auto foldr = accumulate(rbegin(v1), rend(v1), 0,
      [](int &i, int &j){cout<<i<<"+"<<j<<endl;return i+j;});
     
      cout <<"= "<< foldr << endl;   
}