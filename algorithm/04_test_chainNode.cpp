#include<iostream>
#include<vector>
#include "00_he_testTime.cpp"
#include "04_linearlist_chainNode.cpp"

using namespace std;
//依照书上实现简单链表 并练习模板编程 
int main()
{
     chain<int> c(10);
     c.push_back(1);
     c.push_back(2);
     c.push_back(3);
     c.push_back(4);
     c.push_back(5);
     c.push_back(6);
     c.push_back(7);
     c.push_back(8);

     c.insert(3 ,9);
     
     c.output(); cout<< endl;

      chain<string> v(10);
    
    function<void( chain<string>&, string)>  pp 
    = &chain<string>::push_back;

    //参数过多 使用bind 提前绑定参数以符合时间测量回调
    function<void()>  ppp 
    = bind( &chain<string>::push_back, &v , "a");

    used_time(ppp, 10000);  //时间测量 100000 20s 及其慢 

    function<void()>  ccc 
    = bind( &chain<string>::get, &v , 9000); 

    used_time(ccc, 10000); //时间测量
}
