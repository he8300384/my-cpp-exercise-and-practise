#include<iostream>
#include<vector>

using namespace std;

//使用快排的划分操作
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

template< typename IT, typename T>
IT pick(T &v, IT p, IT q, int k)
{   
    if(!(0< k && k <= v.size()))//k合法检查
    {
        cout << "not find\n";
        return v.end() ;   
    }

    IT r = partition(p, q);
     
    int count = distance(v.begin(), r); // 迭代器没办法与int 比较这里用distance 可知迭代器位置
    if(count == k-1) return r; 

    if(count <  k) return pick(v, r+1 , q, k ); //寻找左侧
    if(count >= k) return pick(v, p , r-1, k ); //寻找右侧
     
   
}

int main()
{
    vector<int> v{7,3,4,5,6,8,2,9};
    vector<int>::iterator i;
    
    //输出第几大的数
    cout<<   *pick(v, v.begin(), v.end()-1, 3);  

}