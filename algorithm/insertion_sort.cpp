#include<iostream>
#include<vector>

using namespace std;

//插入排序 升序
template<typename T>
void insertion_sort(vector<T> &A)
{
    for(int j = 1; j < (A.size() ); ++j) //遍历容器元素
    {
       T key = A[j];                    
       int i = j - 1;
        //遍历处理过的元素 寻找最大的放在  key 的坑位 遍历过的元素会每次循环会变大
       while(i>=0 && A[i]>key)     //   key 和目前元素比 目前元素大他就放至key         
       {
           A[i+1] =A[i];
           A[i] =key;
           i= i-1;  
       }
     }
}

//插入排序 降序
template<typename T>
void insertion_sort_r(vector<T> &A)
{
    for(int j = 1; j < (A.size() ); ++j) //遍历容器元素
    {
       T key = A[j];                    
       int i = j - 1;
        //遍历处理过的元素 寻找最大的放在  key 的坑位 遍历过的元素会每次循环会变大
       while(i>=0 && A[i]<key)     //   key 和目前元素比 目前元素大他就放至key         
       {
           A[i+1] =A[i];
           A[i] =key;
           i= i-1;  
       }
     }
}


int main()
{
    vector<int> v{3,1,2,4,6,2,1,1,6,9,5};

    insertion_sort(v);

    for(auto i: v)
      cout << i  ;

    insertion_sort_r(v);

    cout << endl;

    for(auto i: v)
    cout << i  ;

}
