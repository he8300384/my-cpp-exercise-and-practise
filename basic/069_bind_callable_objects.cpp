#include<functional>
#include<iostream>

using namespace std;

struct B
{
    void operator()(int b, const string& message)
    {
    cout << b <<" "<<  message << endl;
    }
    static void show1(int b, const string& message)
    {
    cout << b <<" "<<  message << endl;
    }
    void show(int b, const string& message)
    {
    cout << b <<" "<<  message << endl;
    }
};

void show(int, const string&);

int main(){
    //1 普通函数bind     function<void(int, const string&) 可用auto
    function<void(int, const string&)> fn1 = bind(show, placeholders::_1, placeholders::_2);
    fn1(1 , "bind普通函数后调用");

    //2 类的静态成员函数 bind 
    function<void(int, const string&)> fn2  = bind(B::show1, placeholders::_1, placeholders::_2);
    fn2(2 , "包装器包装静态成员函数后调用");

    //3 仿函数bind 
    B b;
    function<void(int, const string&)> fn3  = bind(B(), placeholders::_1, placeholders::_2);
    fn2(2 , "包装器包装静态成员函数后调用"); 
    fn3(3 , "包装器包装仿函数后调用");
    
    //4 lambda 函数bind 
    auto la = [](int b, const string& message){cout << b <<" "<<  message << endl;};
    function<void(int, const string&)> fn4 = bind(la, placeholders::_1, placeholders::_2);
    fn4(4 , "包装器包装lambda函数后调用");

    //5 类的非静态成员函数bind 
    B b1;
                                                     //注意 写法又不一样 多一个参数 用来传递实例
    function<void(B&, int, const string&)> fn5  =bind(&B::show, placeholders::_1, placeholders::_2, placeholders::_3); 
    fn5(b1, 5, "包装器包装普通成员函数后调用");//这样不能用于模板 可以提前绑定对象 方便模板化
    
    //以下方法在类中的定义较为方便因为可以使用this指针 
    function<void(int, const string&)> fn5_2  =bind(&B::show, &b1, placeholders::_1, placeholders::_2); //注意用引用 
    fn5_2(5, "包装器包装普通成员函数 提前绑定实例 减少调用参数 后调用");//可用于模板

    
    //6 可以被转换为函数指针的类
    B b2;
    function<void(int, const string&)> fn6  =bind(b2, placeholders::_1, placeholders::_2); 
    fn6(6 , "包装器包装可以被转换为函数指针的类");
}

//定义普通函数
void show(int b, const string& message){
    cout << b <<" "<<  message << endl;
}