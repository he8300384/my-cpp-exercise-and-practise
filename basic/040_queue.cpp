#include<iostream>
#include<queue>
#include<list> //双链表
using namespace std;

 

int main(){
     //queue<int, vector<int>> q;//不能创建 不支持vector
     queue<int, list<int>> q;//第二个是容器类型
     queue<int> q2;// 默认就是list
     for(int i=0; i<10000; i++)
        //q.push(i);
        q.emplace(i);//效率更高
     
     for(int i=0; i<10000; i++)
     {
        cout<<q.front()<<" \t";
        if(i%10 == 0)
        cout<<endl;
        q.pop();
     }
        
 
}