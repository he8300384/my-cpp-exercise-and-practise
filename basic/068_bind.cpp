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



using F = void(int, const string&); //函数类型 别名

F show; //用别名声明普通函数

int main(){
    //指向普通函数
    function<void(int, const string&)> fn1  = show;
    fn1(1 , "包装器包普通函数后调用");
    //指向绑定对象
    function<void(int, const string&)> fn2  = bind(show, placeholders::_1, placeholders::_2);
    fn2(2 , "包装器包装bind后的函数后调用");
    //调换参数顺序
    function<void(const string&, int)> fn3 = bind(show, placeholders::_2, placeholders::_1); 
    fn3("包装器包装bind调换参数位置后调用", 3); //参数可以调换使用了
    //减少参数数量
    int num = 4;
    function<void(const string&)> fn4  = bind(show, num, placeholders::_1);//num是值传递
    function<void(const string&)> fn5  = bind(show, std::ref(num), placeholders::_1);//这样才是引用传递
    num = 5;//绑定后要修改参数需要时引用传递 
    fn4("包装器包装bind后减少参数后调用"); //提前绑定了参数 此时调用函数就只需要一个参数了
    fn5("包装器包装bind后引用参数后调用"); //绑定后要修改参数需要时引用传递 
    //增加参数数量
    function<void(int,const string&,const string&)> fn6  = bind(show, placeholders::_1, placeholders::_2); 
    fn6(6 , "包装器包装bind多余参数后调用", "多余参数");//多出来的参数

}

//定义普通函数
void show(int b, const string& message){
    cout << b <<" "<<  message << endl;
}