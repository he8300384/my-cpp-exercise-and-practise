#include <iostream>
#include <vector>
#include <algorithm> //copy
#include <cstddef>   //ptrdiff_t
#include <iterator>  //ostream_iterator
#include <functional>
#include "00_he_testTime.cpp"

//基于内置vector实现线性表 我只实现了几个函数  目前想尽快全局的实验 数据结构

using namespace std;
//线性表抽象基类 ADT描述
template <class T>
class linearList
{
public:
    virtual ~linearList(){};                                    //纯虚基类必须虚化析构
    virtual bool empty() const = 0;                             //是否为空
    virtual int size() const = 0;                               //元素个数
    virtual T &get(int theIndex) const = 0;                     //取元素
    virtual int indexOf(const T &theElement) const = 0;         //元素第一次出现的索引
    virtual void erase(int theIndex) = 0;                       //删除元素
    virtual void insert(int theIndex, const T &theElement) = 0; //插入元素
    virtual void output( ) const = 0;                //输出线性表内容
};

template <class T>
class vectorList : public linearList<T>
{
     template <class TT> friend ostream &operator<<(ostream &out, const vectorList<TT> &x);
public:
    vectorList(int initialCapacity = 10);
    vectorList(const vectorList<T> &);
    ~vectorList()
    {
        delete element;
        element = nullptr;
    }

    bool empty() const { return element->empty(); }   //套接了vector方法
    int size() const { return (int)element->size(); } //套接了vector方法
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output( ) const;

    void push_back(const T &theElement) ;

    int capacity() const { return (int)element->capacity(); } //套接了vector方法

protected:
    void checkIndex(int theIndex) const;
    vector<T> *element;
};

int main()
{
    vectorList<string> v(10);
    
    function<void( vectorList<string>&, string)>  pp 
    =  &vectorList<string>::push_back;

    //参数过多 使用bind 提前绑定参数以符合时间测量回调
    function<void()>  ppp 
    = bind( &vectorList<string>::push_back, &v , "a");


    used_time(ppp, 1000000);     

    cout<<"数组大小" << v.size() << "  空间占用"<< v.capacity() << endl;


    vectorList<string> v2(10);

    v2.push_back("a");
    v2.push_back("b");
    v2.push_back("c");
    v2.push_back("d");
    v2.push_back("e");

    v2.insert(1,"aa");

    v2.output();
    
}

template <class T>
vectorList<T>::vectorList(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        cout << "初始化长度要大于0\n";
        initialCapacity = 1;
    }

    element = new vector<T>;
    element->reserve(initialCapacity);
}

template <class T>
vectorList<T>::vectorList(const vectorList<T> &thelist)
{
    element = new vector<T>(*thelist.element);
}


template <class T>
void vectorList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex > element->size())
    {
        // ostringstream s;
        // s<<"index = " << theIndex << "size = " << listSize;
        // throw illegalIndex(s.str());
        cout << "非法索引";
        cout << " index = " << theIndex << " size = " << element->size() << endl;
    }
}

template <class T>
void vectorList<T>::insert(int theIndex, const T &theElement)
{
    checkIndex(theIndex);
    element->insert(element->begin() + theIndex, theElement);
}

template <class T>
void vectorList<T>::erase(int theIndex )
{
  checkIndex(theIndex);
  element->erase(element->begin()+theIndex);
}


template <class T>
int vectorList<T>::indexOf(const T &theElement) const
{
    return 0;
}

template <class T>
T &vectorList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return (*element)[theIndex];
}

template <class T>
void vectorList<T>::output( ) const
{
    for(int i=0; i<element->size();i++)
    {
        cout<<  (*element)[i] << " ";
    }
}

template <class T>
  void vectorList<T>::push_back(const T &theElement) 
  {
    element->push_back(theElement);
  }


template <class T>
ostream &operator<<(ostream &out, const vectorList<T> &x)
{
    // x.output(out); //书上传参没成功 用了简单直接的友元函数方式 书上方式倒是可以避免写友元
    auto  v= x.element ;
    for (int i = 0; i <  v->size() ; i++)
        out <<   (*v)[i]   << " ";
    return out;
}