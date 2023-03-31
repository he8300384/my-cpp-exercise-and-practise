#include<thread>
#include<iostream>
#include<string>
#include<deque> //容器
#include<queue> //容器
#include<mutex> //互斥锁
#include<condition_variable> //条件变量
#include<functional>

using namespace std;

//用于回调的可调用对象
 void show1() {
   cout << "你好 \n";
 }

 
 void show2(string s) {
   cout << "普通函数回调处理 " << s << " \n";
 }

 
 struct S
 {
   void show3(string s) {
      cout <<  "类成员函数回调处理 " << s << " \n";
   }
 };


class A
{
    mutex m_mutex;                      //互斥锁
    condition_variable m_cond;          //条件变量
    queue<string, deque<string>> m_q;   //缓存队列 底层时deque
    function<void(const string&)> m_callback;//回调函数 bind后的可调用对象

public:

//b回调函数的模板函数
template<typename Fn, typename ...Args>
void callback(Fn&& fn, Args&& ...args){
    //bind比较不好理解可以看上面几课例子
    m_callback = bind(forward<Fn>(fn), forward<Args>(args)..., std::placeholders::_1);    
}

void incache(int num) //生产数据 num指定数据个数
{
    lock_guard<mutex> lock(m_mutex);//申请加锁 lock gard离开作用域 会自动释放锁
    for(int i = 0; i < num; i ++)
    {
        static int n = 1; //数据编号
        string message = to_string(n++)+ " 号数据"; //拼接一个数据
        m_q.push(message); //数据入队
    }
    //m_cond.notify_one();  //唤醒被当前条件变量阻塞的一个线程 这个线程会处理所有数据 数据只有一个才用
    m_cond.notify_all();   //唤醒被当前条件变量阻塞的所有线程 这些线程会处理所有数据
}

void outcache() //消费者线程 不断处理数据 没有数据就等待
{
    while(true) //永远循环
    {   
        {//作用域用于释放锁
            //cout << "线程: " << this_thread::get_id() << " 申请加锁" << endl;
            unique_lock<mutex> lock(m_mutex);//unique_lock类似lock gard参数是普通互斥锁
            //cout << "线程: " << this_thread::get_id() << " 加锁成功" << endl;

            //没有任务会一直等待
            while (m_q.empty()) //队列非空 不进入循环 直接处理数据  有虚假唤醒没得到数据的线程应继续等待 不能用if 
                m_cond.wait(lock);//阻塞线程 等待生产者信号

            //数据元素出队
            string message = m_q.front(); m_q.pop();
            cout << "线程: " << this_thread::get_id() << "生产：" << message << endl;

            //模拟处理数据 
            if(m_callback) m_callback(message);
        }//作用域用于释放锁 用完就释放 不要蹲着茅坑不拉屎
    }   
}

};

int main(){ 
    A a;
    // a.callback(show2);//注册普通函数
    S s;
    a.callback(&S::show3, &s);//注册成员函数 一般用类的成员函数


    thread t1(&A::outcache, &a); //创建 消费者 线程 outcache 是死循环会一直存在
    thread t2(&A::outcache, &a); //创建 消费者 线程 outcache 是死循环会一直存在
    thread t3(&A::outcache, &a); //创建 消费者 线程 outcache 是死循环会一直存在

    this_thread::sleep_for(chrono::seconds(2));//休眠2秒
    a.incache(3); //生产3个数据

    this_thread::sleep_for(chrono::seconds(3));//休眠3秒
    a.incache(7); //生产7个数据

    t1.join();
    t2.join();
    t3.join();
    
}