#include<iostream>
#include<algorithm>
#include<vector>  
//#include<string>
using namespace std;


// void foreach(const vector<int>& v)
// {
//     for(auto i = v.begin(); i != v.end(); i++)
//         cout<< *i << " ";
//     cout <<endl;    
// }

// void foreach(const vector<int>::iterator first, const vector<int>::iterator end)
// {
//     for(auto i = first; i != end; i++)
//         cout<< *i << " ";
//     cout<<endl;
// }

template<class T>
class func1
{
     
    public:
     
    void operator ()(T s){
        cout <<"调用函数类显示：" << s << endl;
    }
    // operator ()(sting a)
    // {
    //     show()
    // }
};

// template<typename T>
// void foreach(T first, T end, void(*pfun)(const string&)) //注意回调函数写法是函数原型
// { 
//     for(auto i = first; i != end; i++)
//     {
//         cout<< *i << " ";   
//         pfun(*i);  //回调函数
//     }
       
// }

// template<typename T>
// void foreach(T first, T end, func1& c) //传类
// { 
//     for(auto i = first; i != end; i++)
//     {
//        // cout<< *i << " ";   
//         c(*i) ;  //回调类  类函数
//     }
       
// }

template<typename T1 ,typename T2>
void foreach(T1 first, T1 end, T2 c) //传类
{ 
    cout<<"调用更简易的函数模板\n";
    for(auto i = first; i != end; i++)
    {
       // cout<< *i << " ";   
        c(*i) ;  //回调类  类函数
        
    }
       
}



template<typename T>
void func(const T& info){
    cout << "回调函数函数显示："<< info << endl;
}

int main(){
     vector<string> a = {"1","2","3","4","5","6","7","8"};
     //foreach(a); 
    
    foreach(a.begin()+2,a.end(), func<string>); //模板支持

     
    foreach(a.begin()+2,a.end(), func1<string>()); //func1() 是匿名对象 func1<string>() 是模板函数具象化
}