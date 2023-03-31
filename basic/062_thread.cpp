#include<thread>
#include<iostream>
#include<windows.h>
#include<mutex> //once flag   call once


using namespace std;

once_flag onceflag;//线程锁

void oncefunc(const char* a)
{
    cout << "调用一次的函数" << a << endl;
}

void show(const char* a)
{
    call_once(onceflag, oncefunc ,"函数1");
    for(int i = 0; i < 10; i++)
    {
        cout<< a <<"普通函数任务执行中....\n";
        this_thread::sleep_for(chrono::seconds(1)); //使用sleep for 函数 跨平台方便
    }
}

class show2
{
    public:
    void operator ()(const char* a){
         for(int i = 0; i < 10; i++)
    {
        cout<< a <<"仿函数任务执行中....\n";
        cout << "线程ID: " << this_thread::get_id() <<endl;
        Sleep(1000);
    }
    }
};

class show3
{
    public:
    static void func(const char* a){
         for(int i = 0; i < 10; i++)
    {
        cout<< a <<"静态函数函数任务执行中....\n";
        Sleep(1000);
    }
    }
    void func2(const char* a){
         for(int i = 0; i < 10; i++)
    {
        cout<< a <<"普通成员函数函数任务执行中....\n";
        Sleep(1000);
    }
    }
};

int main(){

    auto f = [](const char* a){for(int i = 0; i < 10; i++)
    {
        cout<< a <<"lambda函数任务执行中....\n";
        Sleep(1000);//win 函数
    }};

    show3 s1;

    //子线程  main是主线程
    thread t1(show, "线程1:     "); //普通函数
    thread t2(f   , "线程2:     "); //lambda函数
    thread t3(show2(), "线程3:     "); //传入仿函数匿名对象
    thread t4(show3::func, "线程4:     "); //传入静态成员函数
    thread t5(&show3::func2, &s1, "线程5:     "); //传入普通成员函数 注意写法 多了对象地址  注意对象生命周期


    cout<<"任务开始\n";
    for(int i = 0; i < 10; i++)
    {
        cout<<"main函数任务执行中....\n";
        Sleep(1000);
    }
    cout << "任务完成\n";

    //获取线程ID
    cout << "线程ID: " << this_thread::get_id() <<endl;
    cout << "线程ID: " << t2.get_id() <<endl;
    
    thread  t6 = move(t1);//移动构造

    //回收线程资源
    t1.join();//移后再释放会错误
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
}