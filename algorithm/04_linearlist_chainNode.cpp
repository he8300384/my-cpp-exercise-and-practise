#include<iostream>
#include<vector>

using namespace std;
//依照书上实现简单链表 并练习模板编程 

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
    virtual void insert(int theIndex, const T& theElement) = 0;
    virtual void output () const = 0;
};

template <class T>
//链表节点
struct chainNode
{
    T element;
    chainNode<T> *next;

    chainNode() {}
    chainNode(const T &element) {this->element = element;}
    chainNode(const T& element ,chainNode<T> *next){this->element = element;this->next = next;}
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
    void insert(int theIndex, const T& theElement);
    void output () const;  

    void push_back(const T& theElement)
    {
        chainNode<T> *newNode = new  chainNode<T> (theElement, NULL);
        chainNode<T> *p = firstNode;
        if(listSize == 0)
            firstNode =  newNode;
        else
        {  
            while(p->next != NULL) //移动指针至元素前 1 位置
                p = p->next ;
            p->next = newNode;
        }    
        listSize++;
    }

    protected:
    void checkIndex(int theIndex) const;
    chainNode<T> *firstNode;
    int listSize;
};

int main()
{
     chain<int> c(10);
     c.push_back(1);
     c.push_back(2);
     c.push_back(3);
     c.push_back(4);
     c.push_back(5);
     c.push_back(6);
     c.push_back(7);
     c.push_back(8);

     c.insert(3 ,9);
     c.erase(6);

     c.output();
}

template<class T>
chain<T>::chain(int initialCapacity)
{
    if(initialCapacity < 1)
        cout<< "init size must > 0";
    firstNode = NULL; 
    listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{
    listSize = theList.listSize;
    if(listSize == 0){firstNode == 0; return;}

    chainNode<T>* sourceNode = theList.firstNode; //从源对象第一节点开始复制
    firstNode = new chainNode<T>(sourceNode->element);
     
    sourceNode = sourceNode->next;//源节点滑动置下一个
    chainNode<T>* targetNode = firstNode;
    //遍历复制链表
    while ((sourceNode!=NULL))
    {
         targetNode->next = new chainNode<T> (sourceNode->element);
         targetNode = targetNode->next;
         sourceNode = sourceNode->next;
    }
    targetNode->next = NULL; //链表尾部设为空
}

template<class T>
chain<T>::~chain()
{
    while (firstNode !=NULL)
    {
        chainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }  
}


template<class T>
T& chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);

    chainNode<T>* currentNode = firstNode;
    //移动指针至元素位置
    for(int i = 0; i< theIndex; i++)
        currentNode = currentNode->next;

    return currentNode->element;    
}

template<class T>
int chain<T>::indexof(const T& theElement) const
{
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    //关键搜索语句在循环条件里
    while (currentNode != NULL && currentNode->element != theElement)
    {currentNode = currentNode->next; index++;}

    if(currentNode == NULL) return -1;
    else return index;
}

template<class T>
void chain<T>::erase(int index)
{
    checkIndex(index);

    chainNode<T>* frontNode = firstNode;
    chainNode<T>* eraseNode = firstNode->next ;

    if(index == 0)
    {
        eraseNode == firstNode;
        firstNode == firstNode->next ;
    }
    else
    {
    for(int i = 0; i< index; i++)
        {
            frontNode= frontNode->next ;
            eraseNode = eraseNode->next ;
        }
    }
    frontNode->next  = eraseNode->next;
    listSize--;
    delete eraseNode;

}

template<class T>
void chain<T>::insert(int index, const T& theElement)
{
    checkIndex(index);
    if(index == 0)
        firstNode = new chainNode<T> (theElement, firstNode);
    else 
    {
        chainNode<T> *p = firstNode;
        //移动指针至元素前 1 位置
        for(int i = 0; i < index -1; i++)
            p = p->next ;
        //注意下一行的3重含义   移动指针至元素前 1 位置 next指针指向 新创建的空间 同时构造函数把新空间的next 指向后面元素     
        p->next = new chainNode<T>(theElement, p->next );//p->next是上一个元素指向的位置 自己接棒 
    }   
    listSize ++; 
}


template<class T>
void chain<T>::output() const
{
    if(firstNode == NULL){cout<<"无内容\n"; return;}
    chainNode<T> *p = firstNode;
    while(true)
    {
        cout<< p->element << " ";
        p = p->next ;
        if(p == NULL) break;
    }
}

template<class T>
void chain<T>::checkIndex(int theIndex)const
{
   if(theIndex < 0 || theIndex > listSize)
    {
        cout<< "非法索引\n";
        theIndex = listSize;
    }
}