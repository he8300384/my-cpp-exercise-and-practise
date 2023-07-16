#include <iostream>
#include <vector>
#include <algorithm> //copy

using namespace std;

template<class T> 
class mystack // 抽象基类
{
    public:
    virtual ~mystack(){}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& top() = 0;
    virtual void pop() = 0;
    virtual void push(const T& theElement) = 0; 
};

//书上用了多继承 数组线性表 我这里直接使用vector实现 不那么啰嗦 很简陋 只是用来实验算法

template<class T>
 class vectorStack:public mystack<T>
 {
    vector<T>* element;
    public:
    ~vectorStack(){delete element;};
    vectorStack(int initSpace = 1) {element =new vector<T>(initSpace);}
    bool empty() const {return element->empty();}
    int  size()  const {return element->size(); }
    T& top()
    {
        if( element->empty()){cout<< "no element on top\n" ;}
        return   (*element)[element->size()-1]   ;
    }

    void pop()
    {
        if( element->empty()){cout<< "no element to pop\n";return;}
        element->pop_back();
    }

    void push(const T& theElement)
    {
        element->push_back(theElement);
         
    }

    void output() const
    {
        for(auto i: *element) 
            cout << i << " ";
    }
    
 };
 
 int main()
 {
    vectorStack<string> v(1);
    v.push("a");
    v.push("b");
    v.push("c");
    v.push("d");
    v.push("e");
    v.push("e");
    v.push("e");
    v.push("t");

    v.output();
    cout<<endl;
    cout<<v.top()<<endl;
    v.pop();
    cout<<v.top()<<endl;
 }
 
 
 
 
 
 
 
 
 
 
 
 
