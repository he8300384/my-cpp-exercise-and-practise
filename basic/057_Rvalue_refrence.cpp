#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class A
{
    public:
    int t =9;
};

A getTemp()
{
    return A();
}
 
int main(){
    int && a=3; //3是右值 
    int b =8;
    int && c =b+ 5;
    A&& aa = getTemp(); //右值引用给 零时变量续命

    cout<<"a = "<< a <<endl;
    cout<<"b = "<< c <<endl;
    cout<<"c = "<< aa.t <<endl;
     
}