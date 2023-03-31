#include<iostream>
#include<string.h>

using namespace std;

void fun1(string &s)
{
    s = "adfa";
}

void fun2(int**ptr)//栈地址指向的地址作为参数
{
    *ptr = new int(4); //解引用 往栈内地址空间装入 分配的堆地址
    cout<< "分配堆地址:"<< (long long)*ptr <<"  栈地址："<<(long long) &ptr << "值： " << **ptr << endl;
}


void fun3(int*&ptr)//栈地址指向的地址引用作为参数
{
    ptr = new int(5); //解引用 往栈内地址空间装入 分配的堆地址
    cout<< "分配堆地址:"<< (long long)ptr <<"  栈地址："<<(long long) &ptr << "值： " << *ptr << endl;
}

void fun4 (const string &s)
{
     cout<<s<<endl;
}

//返回引用
int& fun()
{
    int * ptr = new int(13);
    int & p = *ptr;
    cout <<"分配堆地址：" << (long long)ptr<< endl;
    return p;
}

int main()
{
    string name = "sdf";

    string       &n =  name; //引用必须立即初始化 且不能更改 其实就是指针常量
    string* const m = &name;//与上面同样的效果

    cout<< n <<"  "<< (long long)&name<<"  "<< (long long)&n<<endl;

    fun1(name);//

    cout<< name <<"  "<< (long long)&name<<"  "<< (long long)&n<<endl;

    int* p = nullptr;//定义指针用于指向堆       

    fun2(&p);//将存储指针的栈地址传入
    delete p;

    fun3(p);//引用传值写法简单
    delete p;

    //const 对于引用
    const int& a=8;
    //fun1("sfda"); //对于形参不是const 无法如此操作
    fun4("sfafaaf");//对于形参是const c++创建零时变量 使之可以直接传递

    int &c = fun();

    cout << "地址： "<< (long long)&c <<"值： "<< c << endl;
    delete &c;
}