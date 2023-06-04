#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class larger_than //用于 copy_if 的谓词
{ 
    int m_i; 
    public:
    larger_than(int i):m_i(i){};
    bool operator ()(int x)const {return x > m_i ;};  
};

int main()
{
    vector<int> v1{1,2,4,5,7};
    vector<int> v2(v1.size()) ; //std  copy_if 不做范围检查 需自行防止越界
     
    copy_if(v1.begin(), v1.end(), v2.begin(), larger_than(3));

    for(auto i: v2) cout << i << " ";
    cout << endl;
     
}