#include<iostream>

using namespace std;

class A
{
    private:
    int a; int b; double c;
    public:
    A(double cc) { c == cc+1; cout << " 构造1\n";}
    A(int aa, int bb) { a == aa+1;b = bb + 1 ; cout << " 构造2\n";}
    A(int aa, int bb, double cc):A(aa,bb) { c = cc ; cout << " 委托构造\n";}   
};  

class B:public A
{
    public:
    double e;
    using A::A; //使用基类构造函数
    B(int aa, int bb, double cc):A(aa,bb), e(cc){
        cout << " 子类继承构造\n";
    }
};

int main(){
    A a(1, 2, 3.4);
    B b(1, 2, 3.4);
}