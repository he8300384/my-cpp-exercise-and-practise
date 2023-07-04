#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>

using namespace std;

//二分查找标识位
struct area
{
    int begin;
    int end;
    area(int b, int e):begin(b), end(e){}
    area(){}
};

//自己写的菜逼二分查找 用于测试
void find(vector<int> & v, area a, int num)
{
   

    int m  = floor((a.begin + a.end )/2);

    cout<< m <<endl;
    
    if(num == v[m])  
    {
        cout <<"find:"<<v[m] <<" at "<< m <<endl;
        return  ;
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
     
    if(m == a.begin || m==a.end) return  ;

     
}


struct Test{
    string label;
    area a ;
    int val;
    vector<int> seq;
    bool res  ;
};

istream& operator >>(istream& is, Test& t)
{
    is >> t.label >>  t.val >> t.a.end ; 
    return is;     
}


/*
int test_all(istream &is){
    int error_count = 0;
    for(Test t; is>>t;){
         // r = find(t.seq, t.a, t.val);
        if(r != t.res){
            cout << "测试失败" << t.label
                << "find: "
                << t.seq.size() << " 元素值 = " <<t.val
                << "--> " << t.res <<endl;
                ++error_count;
        }
    }
    return error_count;
}
*/
int main()
{
     ifstream is("test.txt");
     Test t;
     is >> t;
     cout << t.label << t.val;
}