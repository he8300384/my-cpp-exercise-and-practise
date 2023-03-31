#include<thread>
#include<iostream>
#include<windows.h>
#include<mutex> //once flag   call once


using namespace std;

mutex mtx;//创建互斥锁保护cout
mutex mtx2;//保护全局变量以得到正确结果

int aa = 0;

void add(){
    for(int i=0; i<=100000; i++)
    {
        mtx.lock(); //申请加锁
        aa++;
        mtx.unlock(); //解锁
    }
}

void oncefunc(const char* a)
{
    cout << "调用一次的函数" << a << endl;
}

void show(const char* a)
{
     
    for(int i = 0; i < 10; i++)
    {   
        mtx.lock();     //互斥锁保护cout
        cout<< a <<"普通函数任务执行中....\n";
        mtx.unlock();   //互斥锁保护cout

        this_thread::sleep_for(chrono::seconds(1)); //使用sleep for 函数 跨平台方便
    }
}

int main(){ 
    //子线程  main是主线程
    // thread t1(show, "线程1:     "); //普通函数
    // thread t2(show, "线程2:     "); //普通函数
    // thread t3(show, "线程3:     "); //普通函数

    thread t4(add); //普通函数
    //thread t5(add); //普通函数

    
    cout<<"两个线程全局变量自增结果应该是20万:" << aa << endl;
 
    cout<<"任务开始\n";
    for(int i = 0; i < 10; i++)
    {
        cout<<"main函数任务执行中....\n";
        Sleep(1000);
    }
    cout << "任务完成\n";

    //回收线程资源
    // t1.join();//移后再释放会错误
    // t2.join();
    // t3.join();
    t4.join();
    //t5.join();
   
}