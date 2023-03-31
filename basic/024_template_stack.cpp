#include<iostream>
#include<string.h>

using namespace std;
 
template<class T>//模板类实现 多类型栈
class Stack
{
    T* items;
    int stacksize;
    int top;
public:
    Stack(int size):stacksize(size), top(0){
        items = new T [stacksize];
    }
    ~Stack(){
        delete[] items; items = nullptr;
    }
    bool isempty() const{return top == 0;}

    bool isfull() const{return top == stacksize;}

    bool push(const T& item) { 
        if(top < stacksize){items[top++] = item; return true;}
        return false;
        }
    bool pop(T& item){
        if(top>0){item = items[-- top]; return true;}
        cout<<"栈满\n";
        return false;
    }     
};

int main()
{
     Stack<string> ss(5);
     ss.push("1"); ss.push("3"); ss.push("2"); ss.push("4"); ss.push("5"); 

    string out;
     while (ss.isempty( ) ==false)
     {
        ss.pop(out);
        cout<< out << endl;
     }
     
    
}