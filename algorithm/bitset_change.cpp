#include<iostream>
#include<bitset>
#include<string>

using namespace std;

int main(){
    
    //打印字符串的二进制表示
    string s {"hello world"};
    for(auto i:s)
       cout << bitset<8>(i)<<endl;


    cout << "输入整数以显示其十六进制和二进制\n";
    /*
    for(int i; cin >> i;)
    {
        
        cout <<dec <<i <<" == "
            <<hex <<"0x" <<i <<"== "
            <<bitset<8*sizeof(int)>{i} <<'\n'; //无溢出防护
    }*/
}