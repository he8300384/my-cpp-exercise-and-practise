#include<iostream>

class A 
{
    public:
     
    
    void out( )
    {
        std::cout<<"im A\n";
    }
};

class B 
{
    public:

    class A* ma;
    B( A* a):ma(a){ma->out();}
    void out()
    {
        std::cout<<"im B\n";
    }
};


int main(int argc, char const *argv[])
{
    A *  aaa = new A ;
    B *  b= new B(aaa); 
   
        
    return 0;
}
