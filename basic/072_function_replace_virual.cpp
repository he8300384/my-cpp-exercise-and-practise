#include<iostream>
#include<functional>

using namespace std;

struct Animal{
    //virtual void show(){cout <<"动物叫\n";}
    function<void()> m_callback;

    template<typename Fn, typename ...Arge>
    void callback(Fn && fn, Arge && ...arge){
        m_callback = bind(forward<Fn>(fn),forward<Arge>(arge)...);
    }
    void show(){m_callback();}
};

struct Dog:public Animal{
    void show() {cout <<"狗叫\n";}
};

struct Cat:public Animal{
    void show() {cout <<"猫叫\n";}
};

int main()
{
    int id =0;
    cout << "选择动物：";
    cin >> id;
    Animal* ptr = nullptr;

    if(id == 1){
        ptr = new Dog;
        ptr->callback(&Dog::show,(Dog*)ptr);
        }
    else if(id == 2){
        ptr = new Cat;
        ptr->callback(&Cat::show,(Cat*)ptr);
        }

    if(ptr != nullptr){
        ptr->show();
        delete ptr;
    }
}