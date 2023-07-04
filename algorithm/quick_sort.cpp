#include<iostream>
#include<vector>
//使用c++ 实现快速排序
using namespace std;

//快速排序的交换过程  
//这里使用迭代器 可以 免于书写（A， p， q） 中的A 见《算法导论》
template< typename IT>
IT partition(IT p, IT q)     
{  
    IT i = p;
    for( IT j = p + 1; j <= q; ++j)
    {
        if(*j <= *p)
        {
            i += 1;
            swap(*j , *i);
        }  
    }
    swap(*p , *i);
    return i;
}                               

//快速排序主递归过程
//这里使用迭代器 可以 免于书写（A， p， q） 中的A 见《算法导论》
template<typename IT>
void quick_sort(IT p, IT q)
{
    if(p < q ) //在小规模时做优化可加速
    { 
        IT r = partition(p, q);  
        quick_sort(p, r-1);
        quick_sort(r+1, q);
    }
    return;       
}

int main()
{
    vector<int> v{3, 1,123, 2, 4, 6, 0, 5,8,3,11,312};
 
    quick_sort( v.begin(), v.end()-1); //注意 尾部指针不要指向空位

    for(auto i:v)
        cout<< i << " ";
    cout <<endl;
    //cout << *i << endl;

}