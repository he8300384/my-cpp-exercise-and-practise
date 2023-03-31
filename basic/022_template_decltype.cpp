#include<iostream>
#include<string.h>

using namespace std;


class A
{
    friend std::ostream& operator <<(std::ostream& cout ,A& a);
    public:
    int i = 3;
     
};

//重载cout<< 返回类型为 std::ostream& 因为cout本身是标准库的类
std::ostream& operator <<(std::ostream& cout ,A& a)
{
	return cout << a.i ;
}

template<typename T>//模板写法
void func(T& a, T& b)
{
    T tmp =a;
    a = b; a = tmp;
    cout<<"完成交换" << a << " " << b << "\n";
     
}

template<>void func(A& a, A& a1)//具体化模板写法 具化函数模板 申明定义要分文件
{
    int temp = a.i;
    a.i = a1.i;
    a1.i = temp;
     cout<<"具化模板完成交换" << a << " " << a1 << "\n";

}

template<typename T1, typename T2>
auto func2(T1 x, T2 y)->decltype(x+y) //自动推导返回类型  ->decltype(x+y) c11可以不写
{
    decltype(x+y) tmp = x + y;
    cout << tmp << endl;
    return tmp;
}

int func4()
{
    cout<<"调用func4\n";
    return 1;
}

int main()
{
     int a = 11,b = 12;
     func(a, b);

     const char* c="aaf" ; 
     const char* d = "sdf";
     func(c, d);

    A a1;
    A a2;
    func(a1, a2);//类也行

    func2(1 ,2.2);

    decltype(a) da   ; //使得 da 是 a的类型 不会执行表达式

    da =5;

    cout << da << endl;

    decltype(func4()) dc  = 3; //使得dc 是一个 函数返回值类型 这里是整形

    cout << dc << endl;

    decltype((func4)) db  = func4;//使得db 是 函数的引用

    db();
    
    
    
}