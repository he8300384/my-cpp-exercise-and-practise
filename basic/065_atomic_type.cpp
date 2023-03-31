#include<thread>
#include<iostream>
#include<windows.h>
#include<atomic>

using namespace std;

atomic<int> aa = 0; //原子类型也解决计算错误

void add(){
    for(int i=0; i<100000; i++)
    {
        //mtx.lock(); //申请加锁
        aa++;
        //mtx.unlock(); //解锁
    }
}

int main(){ 
   
    thread t1(add);
    thread t2(add);
    this_thread::sleep_for(chrono::seconds(1)); //使用sleep for 函数 跨平台方便
    cout << aa <<endl;
 
    //原子类型操作
    aa.load();          //显示原子变量值
    aa.store(8);        //把值存储在原子变量
    aa.fetch_add(5);    //值加5 返回原值
    aa.fetch_sub(2);    //减2   返回原值

    int expect =3;  
    bool len = aa.compare_exchange_strong(expect , 2222); // CAS 比较 值 真的话存储2222 返回bool 更新expect

    t1.join();
    t2.join();
}