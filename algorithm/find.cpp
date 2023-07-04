#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct area
{
    int begin;
    int end;
    area(int b, int e):begin(b), end(e){}
};

//自己写的菜逼二分查找 用于测试
void find(vector<int> & v, area a, int num)
{
   

    int m  = floor((a.begin + a.end )/2);

    cout<< m <<endl;
    
    if(num == v[m])  
    {
        cout <<"find:"<<v[m] <<" at "<< m <<endl;
        return ;
    }

    if(num > v[m]) 
    {
        area ar(m, a.end);
        cout <<"middle = " << v[m] << " find high\n";
        find(v, ar, num);
    }

    if(num < v[m]) 
    {
        area ar(a.begin, m);
        cout  <<"middle = " << v[m] << " find low\n";
        find(v, ar, num);
    }
     
    if(m == a.begin || m==a.end) return ;

     
}

int main()
{
    vector v{1,3,4,6,9,10,22};
    area a(0,v.size() );
    find(v, a,22);
}