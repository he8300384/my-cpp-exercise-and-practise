#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//使用栈 判定括号匹配 前面的类是前面文件拷贝的

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
    void clear() {element->clear();}
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


//! 看这里————————————————————————————————————————————————————————————————————————————————
 void printMatchedPairs(string strings)
 {
    vectorStack<char> stringStack;
    stringStack.clear();//自己写的bud栈 开始有个元素不清不行
    int pairsNumber= 0;
    int RpairsNumber= 0;
    for(auto i : strings)
    {
        if(i == '(')
        {
            stringStack.push(i);
        }
        if(i == ')' && !stringStack.empty())
        {
            pairsNumber ++;
            stringStack.pop();
        } 
        if(i == ')' && stringStack.empty())
            RpairsNumber++;
         
    }
    cout<< "已匹配" << pairsNumber <<"个括号\n"; 

    if(!stringStack.empty())
        cout << "还有 "<< stringStack.size()<<" 个 ( 括号未匹配\n";

    if(RpairsNumber > 0)
        cout<< "还有" << RpairsNumber-1 <<"个 ）括号未匹配\n"; 

   
           
 }
 
 int main()
 {
    printMatchedPairs("(113+(a+q)))  ");
     
 }
 
 
 
 
 
 
 
 
 
 
 
 
