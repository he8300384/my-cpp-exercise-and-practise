#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v1= {1, 2, 3, 4};
    vector<int> v2 ;

    //将值拷贝到流迭代器 
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    
    //使用匹配 过滤函数拷贝  这里过滤条件是偶数
    copy_if(v1.begin(), v1.end(), back_inserter(v2), 
    [](int i){if(i % 2 == 0) return true; else return false;});

     //显示过滤拷贝后的v2
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));  cout << endl;
    
     //使用不匹配 过滤函数拷贝  这里过滤条件是偶数
    remove_copy_if(v1.begin(), v1.end(),back_inserter(v2), 
    [](int i){if(i % 2 == 0) return true; else return false;});

     //显示过滤拷贝后的v2
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
     
}