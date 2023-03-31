#include<iostream>
#include<string.h>

using namespace std;

struct linkList{
    const char* name ;
    int no;
    linkList* next;
};

void out(const linkList* ptr) //可以让参数无法被修改
{
    cout<<"函数输出结构体信息: "; 
    cout<<ptr->name <<"  " << (*ptr).no <<"  "<< (long long)ptr->next  <<"\n";//解引用
}

int main()
{
    linkList* head = nullptr, *tmp = nullptr, *end = nullptr; 

    tmp = new linkList{"aaa", 1, nullptr};
    head = end = tmp;
      

    tmp = new linkList{"bbb", 2, nullptr};
    end->next = tmp;
    end = tmp;

     
    tmp = new linkList{"ccc", 3, nullptr};
    end->next = tmp;
    end =tmp;
     
    //遍历
    tmp = head;
    while(tmp!=nullptr)
    {
         
        out(tmp);
        tmp= tmp->next;
    }

    //释放内存
    tmp = head;
    while(tmp!=nullptr)
    {
        head = tmp->next;
        delete tmp;
        tmp = head;
    }
    
}