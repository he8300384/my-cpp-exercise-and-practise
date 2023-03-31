#include<iostream>
using namespace std;

void func1(int &i){
    cout << "参是左值: "<< i <<endl;
}

void func1(int &&i){
    cout << "参数是右值:" << i <<endl;
}

void func2(int i){
    func1(i); //传递参数无法保证左右值属性
}

template<typename T>
void func (T&& i)           //注意参数 前T&&  int&& 是不行的
{
    func1(forward<T> (i));  //注意参数前forward<T>
}


int main(){
    int ii =3;
    func1(ii);
    func1(8);

    func2(5);
//完美转发的模板函数
    func(5);
    func(ii);
}