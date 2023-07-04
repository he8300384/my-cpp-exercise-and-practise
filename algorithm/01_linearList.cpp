#include<iostream>
#include<vector>

using namespace std;


//线性表抽象基类
template<class T>
class linearList
{
    public:
    virtual ~linearList(){};                             //纯虚基类必须虚化析构
    virtual bool empty() const = 0;                      //是否为空
    virtual int  size() const = 0;                       //元素个数
    virtual T&   get(int theIndex) const = 0;            //取元素
    virtual int  indexof(const T& theElement) const = 0; //元素第一次出现的索引
    virtual void erase(int theIndex) =0;                 //删除元素
    virtual      voidinsert(int theIndex, const T& theElement) = 0; //插入元素
    virtual void output (ostream& out) const = 0;        //输出线性表内容
};

 
int main()
{
    cout << "纯虚函数无实例";
}