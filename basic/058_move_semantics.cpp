#define _CRT_SECURE_NO_WARNINGS //不跳出c函数 安全警告
#include <iostream>
#include<string.h>

using namespace std;

class A
{
    public:
    int* data = nullptr;
    A() = default; //默认构造

    void alloc(){
        data = new int;
        memset(data, 0, sizeof(int));
    }
    
    A(const A &a ){  //普通拷贝  堆区新分配搬运旧内容
        cout<<"调用普通拷贝构造\n";
        if(data == nullptr) alloc();
        memcpy(data, a.data, sizeof(int));
    }

    A( A &&a ){   //移动拷贝 只改变指针不会堆区新分配 改变源对象指针 所以不能const
        cout<<"调用移动拷贝构造\n";
        if(data != nullptr) delete data;
        data = a.data;
        a.data = nullptr;
    }

    A& operator =(const A&a){//普通赋值
        cout<<"调用普通赋值函数\n";
        if(this == &a) return *this;
        if(data == nullptr)alloc();
        memcpy(data, a.data, sizeof(int));
        return *this;
    }

    A& operator =( A&&a){ //移动赋值
        cout<<"调用移动赋值函数\n";
        if(this == &a) return *this;
        if(data != nullptr)delete  data;
        data = a.data;
        return *this;
    }

    ~A(){
        if(data != nullptr){
            cout<<"析构\n";
            delete data; data = nullptr;
        }
    }
};

int main()
{
    A a1;
    a1.alloc();
    *a1.data = 3;
    //普通构造 和复制构造
    A a2;
    a2 = a1;

     //右值引用 带来的移动构造
    // auto f = []{A aa; aa.alloc(); *aa.data = 8;return aa;};
    // A a3 = a1;
    // A a4 = f();

    // A a5;
    // a5 = f();

    A a3 = move(a1);
    A a4;
      a4 = move(a1);  
}