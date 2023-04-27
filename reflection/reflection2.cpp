#include<iostream>
#include<string>

#define REFLECT

class Person{
    int age;
    std::string name;

    //REFLECT(age , name)
    
    public:
    Person(int a, std::string n):age(a),name(n){}
    void run(){std::cout<<name << " is runing  " << __FUNCTION__ <<std::endl;}
};

template<typename T>
void show(T& aclass)
{
    aclass.run();
}

int main()
{   
    Person p(12 , "anna");
    show(p);

}