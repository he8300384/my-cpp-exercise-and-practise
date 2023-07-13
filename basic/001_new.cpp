#include<iostream>
#include<string>

using namespace std;

struct People
{
   int age;
   string name;

   People(int a, string n):age(a),name(n){}
   People(const People& p):age(p.age),name(p.name){cout<<"拷贝构造\n";}

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
};

template<class T>
struct chain
{
    node<T>* first   ;
    int size = 0;
     
    void append(T &ele )
    {
        node<T>* newNode = new node<T>(ele, NULL);
        node<T>* p = first;
        if(size == 0) 
            first = newNode;
        else
            while(p->next != NULL) 
                p = p->next;
            p->next = newNode;     
        size++;        
    }
};

int main()
{
    People p1(3, "ss");
    People p2(3, "ss");
    People p3(3, "ss");
    People p4(3, "ss");

    car* cc =new car(223, p1);

    chain<People> c;
    c.append( p1);
    c.append( p2);
    c.append( p3);

    cout <<c.size;
}