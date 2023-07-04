#include<iostream>
#include<vector>

using namespace std;
//计数排序
template<typename T>
vector<T> counting_sort(vector<T>& A ,T k) //得知道数据在 0 - k区间
{
    vector<T> C(k+1 , 0);//记录元素出现次数的数组
    vector<T> B(A.size(),0);

    for(int j = 0 ;j < A.size() ; ++j)//记录出现次数
        C[A[j ]] = C[A[j ]] + 1;  

    for(int i = 1 ;i <= k  ; ++i) //累加 说明元素在哪个位置
        C[i] = C[i] + C[i-1];

    for(int j = A.size()-1; j >=  0; --j)
    {           
        B[C[A[j]]-1] = A[j];
        cout << A[j] << "\tmove to    [" << C[A[j]]-1 << "]" << endl;
        C[A[j]] = C[A[j]] -1  ;
    }  
    return B;  
}

int main()
{
    vector<int> v{3,1,4,2,6,2,3,22};

    //计数排序前提是知道 v的元素区间 这里手动给出 7
    vector<int> v2 = counting_sort(v, 22);

    for(auto i:v2)
        cout<< i << " ";
    cout <<endl;
  
} 