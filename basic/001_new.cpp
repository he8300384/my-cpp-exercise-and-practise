#include<iostream>
#include<string>

using namespace std;

struct People
{
   int age;
   string name;

   People(int a, string n):age(a),name(n){}
   People(const People& p):age(p.age),name(p.name){cout<<"拷贝构造\n";}
   People(  People&& p):age(p.age),name(p.name){cout<<"移动构造\n";}
   void out(){cout << name << endl;}
};

struct car
{   
   int num;
   People& pe;
   car(int n, People& p):num(n),pe(p){}  
};

template<class T>
struct node
{
    T element;
    node<T>* next;
    node(T e, node<T>* n): element(e), next(n){}
    node(node && n ): element(n.element), next(n.next){}
};

template<class T>
struct chain
{
    node<T>* first   ;
    int size = 0;
     
    void append(T &&ele )
    {
        node<T>* newNode = new node<T>(move(ele), NULL);
        node<T>* p = first;
        if(size == 0) 
            first = newNode;
        else
        {
            while(p->next != NULL) 
                p = p->next;
            p->next = newNode; 
        }    
        size++;        
    }

    void out()
    {
        node<T>* p = first;
        while(true)
        {
            if(p == NULL) break;
            p->element.out();
            p = p->next;
           
        }
    }
};

int main()
{
    chain<People> c;
    c.append(People(3, "ss"));
    c.append(People(4, "aa"));
    c.append(People(5, "ee"));
    c.append(People(6, "bb"));
    c.append(People(7, "ef"));
    c.append(People(4, "cs"));
    c.append(People(3, "rt"));
    c.append(People(1, "nb"));
     
     c.out();

    cout <<c.size;
}