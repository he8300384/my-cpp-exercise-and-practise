#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>
#include<fstream>

using namespace std;

int main()
{
    //时间长度
    chrono::hours t1(1);
    chrono::minutes t2(60);
    chrono::seconds t3(60*60);
    chrono::milliseconds t4(60*60*1000);

    //获取系统时间 4 个步凑   要研究 usc  titime_t

    //1 静态成员函数获取系统时间
    chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();// auto now2 = chrono::system_clock::now(); 

    //2 用静态成员函数转换时间 为time_t （utc时间）
    time_t t_now = chrono::system_clock::to_time_t(now);

                //时间偏移
                //t_now = t_now + 24*60*60; //加一天


    //3 std::localtime 把time_t时间转换为本地时间 非线程安全 vs用 localtime_s  linux localtime_r
    tm* tm_now = std::localtime(&t_now);

    //4 格式化输出时间
    cout<< put_time(tm_now, "%Y年-%m月-%d日 %H:%M:%S")<<endl;
    

    //保存时间变量

    stringstream ss; //创建字符流对象 输出
    ss<<put_time(tm_now, "%Y年-%m月-%d日 %H:%M:%S");
    string time = ss.str();
    cout<<time <<endl;


    ofstream fout("test04.txt",ios::app); //文件保存
    fout <<time<<endl;
    fout.close();

    //字符串时间 逆向转换为  time_point 对象 比较麻烦需要了解 中间结构 对象 体组成
    //要用到time_point form_time_t()
   

    //计时器
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

    cout << "开始计时.......\n";
    for(int i =0; i< 10000000; i++)
    { }
    cout <<" 计时完成\n";

    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    auto dt = end -start;
    cout << "耗时：" << dt.count() << "纳秒（" << (double)dt.count()/(1000*1000*1000)<<"秒）";
     
}