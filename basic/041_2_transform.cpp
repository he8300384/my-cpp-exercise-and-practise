#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v1= {1, 2, 3, 4};
    vector<int> v2= {0, 0, 0, 0};

    //transform 施加一个变化到序列元素 用一个新序列纪录新值 
    transform(v1.begin(), v1.end(), v2.begin(), [](int a){return a*a;});

    for(auto i:v2)
        cout << i << "  ";
    cout << endl; 
}