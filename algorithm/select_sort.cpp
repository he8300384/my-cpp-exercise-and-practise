#include<iostream>
#include<vector>

using namespace std;

//选择排序  
template<typename T>
void select_sort(vector<T> &A)
{ 
    for(int j = 0; j < A.size()-1; j++) //顺序遍历容器 
    {
        //T key = *j;
        for(int i = j+1; i < A.size(); i++) //遍历剩余项目
        {
            if(A[i] < A[j])             //如果当前项目小于剩余项目 交换两者
                swap(A[i], A[j]);             
        }
    }
}

int main()
{
    vector<int> v{3,1,2,4,6,2,1,1,6,9,5};

    select_sort(v);

    for(auto i: v)
        cout << i;

    cout<< endl;

    //取模数
    for(int i =0; i <20; i++)
    {
        cout<< (i+7)%10 << " "; 
    }
    cout<< endl;
}
