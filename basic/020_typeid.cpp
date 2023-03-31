#include<iostream>
#include<string.h>
#include<typeinfo>

using namespace std;
class a
{
    int i=0;
};

class ac:public a
{

};

int main()
{
    string name;
    int c;
    const char e[12]= "222a";
    a aa;
    ac aac;
    int * b;


    cout<<typeid(a).name()<<"\n";
    cout<<typeid(aa).name()<<"\n";
    cout<<typeid(aac).name()<<"\n";
    cout<<typeid(name).name()<<"\n";
    cout<<typeid(c).name()<<"\n";
    cout<<typeid(e).name()<<"\n";
    cout<<typeid(b).name()<<"\n";
    
}