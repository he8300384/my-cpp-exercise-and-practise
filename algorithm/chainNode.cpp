#include<iostream>
#include<vector>

using namespace std;


//线性表抽象基类
template<class T>
class linearList
{
    public:
    virtual ~linearList(){};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& get(int theIndex) const = 0;
    virtual int indexof(const T& theElement) const = 0;
    virtual void erase(int theIndex) =0;
    virtual  voidinsert(int theIndex, const T& theElement) = 0;
    virtual vois output (ostream& out) const = 0;
};

template <class T>
//链表节点
struct chainNode
{
    T element;
    chainNode<T> *next;

    chainNode() {}
    chainNode(const T &element) 
    {
        this->element = element;
    }
    chainNode(const T& element ,chainNode<T> *next)
    {
        this->element = element;
        this->next = next;
    }
};

template<class T>
class chain : public linearList<T>
{
    public:
    chain(int initialCapacity  = 0);
    chain(const chain<T>&);
    ~chain() ;

    bool empty() const {return listSize == 0;}
    int size() const {return listSize;};
    T& get(int theIndex) const;
    int indexof(const T& theElement) const;
    void erase(int theIndex);
     voidinsert(int theIndex, const T& theElement);
    vois output (ostream& out) const;  

    protected:
    void checkIndex(int theIndex) const;
    chainNode<T> *firstNode;
    int listSize;
};

int main()
{
    cout << "hi";
}