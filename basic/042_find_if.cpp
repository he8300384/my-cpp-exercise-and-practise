#include<iostream>
#include<algorithm>
#include<vector>  
//#include<string>
using namespace std;

 

template<class T >
class func1
{   
    T num;
public:   
    func1(T nu):num(nu){cout<<"仿函数构造\n";}
    bool operator ()(T s){
        
        if (s != num) return false;
        cout <<"回调仿函数函找到：" << s << endl;
        return true;
    }
};

template<typename T>
bool func(const T& info){
    
    if (info != 3) 
    {return false;}
    cout << "回调函数函找到："<< info << endl;
    return true;
}
 

template<typename T1 ,typename T2>
T1 findIf(T1 first, T1 end, T2 c ) //传类
{ 
    cout<<"自定义findif\n";
    for(auto i = first; i != end; i++)
    {
        if(c(*i) == true)
        {return i;}    //回调类  类函数        
    }       
    return end;            
}

int main(){
     vector<int> a = {1,2,3,4,5,6,7,8,9};
     //findIf(a); 
    
    auto it = findIf(a.begin(),a.end(), func<int>); //模板支持
    if(it != a.end()) 
        cout<<"查找成功 "<<*it<<endl<<endl;

    //func1() 是匿名对象 func1<string>() 是模板函数具象化
    //仿函数夹带了参数用于寻找 这是仿函数的意义
    auto it2 = findIf(a.begin(),a.end(), func1<int>(9)); 
    if(it2 != a.end()) 
        cout<<"查找成功 "<<*it2<<endl<<endl;
        
    cout<<"完毕\n";   
}