#define _CRT_SECURE_NO_WARNINGS //不跳出c函数 安全警告
#include<iostream>
#include<vector>
#include <algorithm>  //copy

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
    virtual void insert(int theIndex, const T& theElement) = 0; //插入元素
    virtual void output (ostream& out) const = 0;        //输出线性表内容
};

//改变数组长度
template<typename T>
void changeLength1D(T* &a, int oldLength, int newLength) // &a是地址 T* 是指向这个地址的指针
{
    if(newLength < 0)
         cout << "new length must be >= 0" ;

    T* temp = new T[newLength];              //新分配堆空间数组
    int number = min(oldLength, newLength);  
    copy(a, a+number, temp);                 //拷贝数据到新数组 前两个参数是地址区间 最后一个是目标
    delete [] a;                            //删除旧数组空间                         
    a = temp;                              // 指向新空间
} 

//具体类 arrayList
template<class T>
class arrayList : public linearList<T>
{
public: 
    arrayList(int initialCapacity = 10);  
    arrayList(const arrayList<T>&);
    ~arrayList(){delete [] element;}

    bool empty() const {return listSize;}
    int  size() const {return listSize;}
    T&   get(int theIndex) const;
    int  indexof(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

    int capacity() const {return arrayLength;}
protected:
    void checkIndex(int theIndex) const;
    T* element;
    int arrayLength;
    int listSize = 0;  
};

 
int main()
{
    // int* a = new int[3];  //注意不要在栈空间分配数组
    // a[1] = 3;
    //  
    // changeLength1D ( a, 3, 10);
    //  
    // a[9] = 5;
    // cout <<a[1] <<" "<< a[9] << endl;

    // delete [] a;

     arrayList<int>  *x =  new  arrayList<int>(10) ;
     
   
    //x->insert(1,2);
    
   cout <<x->capacity()  << " " << x->indexof(1); 
}


//arraylist 函数实现

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if(initialCapacity < 1)
    {
        //ostringstream s;
        cout<< "Initial capacity =" << initialCapacity << "Must be > 0";
        //throw illegalParameterValue(s.str());

        arrayLength = initialCapacity;
        element = new T[arrayLength];
        listSize = 0;
    }
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element +listSize, element); //深拷贝
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0 || theIndex >= listSize)
    {
        // ostringstream s;
        // s<<"index = " << theIndex << "size = " << listSize;
        // throw illegalIndex(s.str());
        cout <<"index = " << theIndex << "size = " << listSize;
    }
}


template<class T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}


template<class T>
int arrayList<T>::indexof(const T& theElement) const
{
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    if(theIndex == listSize)
        return -1;
    else return theIndex;    
}

template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    //复制尾部内容到删除点
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();//清除最后一个重复元素
}


template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    if(theIndex < 0 || theIndex > listSize)
    {
        // ostringstream s;
        // s<< "index = " << theIndex<< " size = " << listSize;
        // throw illegalIndex(s.str());
        cout<< "index = " << theIndex<< " size = " << listSize;
    
    }

    if(listSize == arrayLength)//如果满倍增
    {
        changeLength1D(element, arrayLength, 2* arrayLength);
        arrayLength *=2;
    }

    //从后移动后面所有元素给新成员 腾空间
    copy_backward(element + theIndex, 
                  element + listSize, element + listSize +1);

    element[theIndex] = theElement;
    listSize++;
}   

template<class T>
void arrayList<T>:: output(ostream& out) const
{
    //copy(element, element + listSize, ostream_iterator<T>(cout, " "));
}

template<class T>
ostream &operator<<(ostream& out, const arrayList<T>& x)
{
    x.output(out); return out;
}
