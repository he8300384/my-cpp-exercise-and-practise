#define _CRT_SECURE_NO_WARNINGS //不跳出c函数 安全警告
#include <iostream>
#include <vector>
#include <algorithm> //copy

using namespace std;

template <typename T>
void changeLength1D(T *&a, int oldLength, int newLength);

struct mylist
{
    int length;
    int size;
    int *lists;

    mylist(int len)
    {
        length = len;
        lists = new int[length];
        size = 0;
    }

    ~mylist() { delete[] lists; }

    mylist(const mylist &m)
    {
        length = m.length;
        size = m.size;
        int *lists = new int[length];
        copy(m.lists, m.lists + length, lists);
    }
};

int main()
{
    mylist x(10);
    cout << x.length << endl;

    mylist *l = new mylist(20);
    cout << l->length << endl;

    mylist y = x;
    cout << y.length << endl;
    ;

    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    copy_backward(L, L + 2, L + 10);

    for (auto i : L)
        cout << i << " ";
    cout << endl;
}

//改变数组长度
template <typename T>
void changeLength1D(T *&a, int oldLength, int newLength) // &a是地址 T* 是指向这个地址的指针
{
    if (newLength < 0)
        cout << "new length must be >= 0";

    T *temp = new T[newLength]; //新分配堆空间数组
    int number = min(oldLength, newLength);
    copy(a, a + number, temp); //拷贝数据到新数组 前两个参数是地址区间 最后一个是目标
    delete[] a;                //删除旧数组空间
    a = temp;                  // 指向新空间
}
