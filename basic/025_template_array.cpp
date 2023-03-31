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
    Stack(int size= 3):stacksize(size), top(0){
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
        if(top>0){item = items[--top]; return true;}
        cout<<"栈满\n";
        return false;
    } 
    Stack & operator =(const Stack &v)
    {
        delete[] items;
        stacksize = v.stacksize;
        items = new T[stacksize];
        for(int i = 0; i < stacksize; i++) items[i] = v.items[i];
        top  = v.top;
        cout<< "深拷贝\n";
        return *this;
    }    
};

 

template <class T , int len = 10>
class Array
{
    private:
    T items[len];
    public:
    Array(){}
    ~Array(){}
    T& operator [](T ii){return items[ii];}
    const T& operator [](T ii) const {return items[ii];}
};

template <class T >
class Vector
{
    private:
    int len;
    T* items ;
    public:
    Vector(int size =3):len(size){items = new T[len];}
    ~Vector(){delete[] items; items = nullptr;}

    void resize(int size)
    {
        if(size <= len)return;
        T* tmp =new T[size];
        for(int ii = 0; ii< len; ii++) tmp[ii] = items [ii];
        delete [] items;
        items = tmp; //不好的多次 拷贝 注意嵌套 容器时 浅拷贝问题
        len = size;
    }

    int size() const {return len;}

    T& operator [](int ii){
        if(ii >= len) 
        {
        resize (ii +2);
        cout<<"resized\n";
        }
        
        return items[ii];
        }

    const T& operator [](T ii) const {return items[ii];}
};


int main()
{
    Array <int, 30> aa;
    aa[0]=10;aa[1]=20;aa[2]=30;aa[3]=40;aa[4]=50;aa[5]=60;
    for(int i= 0; i<6;i++)
    {
        cout << aa[i] <<"  ";
    }

    Vector<string> vv;
     for(int i = 0; i<11; i++)
    {
        vv[i] ="aa" ;
    }

     for(int i = 0; i<11; i++)
    {
       cout <<  vv[i] << " "  ;
    }

    cout << "\n" << "测试嵌套容器\n"  ;
    Vector<Stack<string>> vs;

    vs[0].push("aaaaa");vs[0].push("bbbbb");vs[0].push("bbbbb");
    vs[1].push("22aaa");vs[1].push("22bbb");vs[1].push("22bbb");
    //深拷贝实验
    vs[2].push("33aaa");vs[2].push("33bbb");vs[2].push("33bbb");

    for(int i = 0;i<3; i++)  
     {
        while (vs[i].isempty() ==false)
        {
            string item;
            vs[i].pop(item);
            cout << item << " ";
        }
        cout << "\n" ;
     }
    cout << "\n" << "测试嵌套容器\n"  ;
     
    Stack<Vector<string>> vs2;

    Vector<string> tmp;
    tmp[0] = "aa"; tmp[1] = "bb"; vs2.push(tmp);
    tmp[0] = "cc"; tmp[1] = "ff"; tmp[2] = "xx"; vs2.push(tmp);
    tmp[0] = "yy";  tmp[1] = "zz";  tmp[2] = "uu"; tmp[3] = "ii"; vs2.push(tmp);

    while (vs2.isempty() ==false)
    {
        vs2.pop(tmp);
        for(int i = 0;i < tmp.size(); i++)
        { 
            cout << tmp[i] << " ";
        }
       cout << "\n" ;
    }
    
    Vector<Vector<string>> vs3;

    vs3[0][1] = "aa";vs3[1][1] = "aa";vs3[1][2] = "aa";

    
}