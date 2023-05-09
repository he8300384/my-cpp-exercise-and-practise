#include<iostream>
#include<functional>

using namespace std;

//延迟执行的模板类
template <class T>
class Delay
{
    function<T()> m_func;
    public:
    Delay(function<T()> func) : m_func(func){}

    T run(){ return m_func();}
};

int main()
{
    int a = 22, b = 5;
    Delay<int> multiply( [a, b](){return a * b;} ); //传入一个lambda函数 此时函数 并不执行
    Delay<int> add( [a, b](){return a + b;} );

    cout << "现在运行函数 \n";

    int c = multiply.run();  
    int d = add.run();

    cout<< c <<"  " << d << endl;

    function<int()> aa ; 
     aa = [a, b](){return a * b;};
     aa();
}