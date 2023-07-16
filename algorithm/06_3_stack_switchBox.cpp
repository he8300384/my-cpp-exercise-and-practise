#include <iostream>
#include <vector>
#include <algorithm>  
#include <stack>  

//开关盒布线问题 检查线对是否交叉
using namespace std;

//线对用于 线脚序号比较 和 出入栈
struct wirePin
{
    int right = 0;
    int left = 0;
    wirePin(int l, int r):left(l),right(r){}
    wirePin(const wirePin& wp):right(wp.right),left(wp.left){}
    bool operator == (int value)const
    {
       if(value == left) return true;
       if(value == right) return true;
       else  return false;
    }

    bool operator != (int value)const
    {   
        return !(*this==value);
    }            

};

void switchBox(int pins,const vector<wirePin> &v)
{
    stack<wirePin> pinstack ;
     
    for(int pin = 1; pin <= pins; pin++)
    {
        if(pinstack.empty())
        {   
            pinstack.push(*(find(v.begin(), v.end(), pin)));  //与序号匹配的 线对入栈
            continue; 
        }
        if(pinstack.top() == pin)
        {
            pinstack.pop();                                  //序号对 成对 出栈
            continue;
        }
            
        if(pinstack.top() != pin) 
            pinstack.push(*(find(v.begin(), v.end(), pin))); //与序号匹配的 线对入栈
    }
    if(pinstack.empty())
        cout<< "可以匹配\n";
    else 
        cout<< "不能匹配\n";    
}


int main()
{
    //! 试验了一下不用先排序线对列表   
    vector<wirePin> wirepins1{wirePin(1,4),wirePin(2,3),wirePin(5,8),wirePin(6,7)};
    vector<wirePin> wirepins2{wirePin(2,3),wirePin(1,4),wirePin(6,7),wirePin(5,8)};
    vector<wirePin> wirepins3{wirePin(2,4),wirePin(1,3),wirePin(5,8),wirePin(6,7)};
    cout<<"一些不会打架顺序排列线对"<< endl;
    switchBox(8, wirepins1);

    cout<< endl<<"同上非顺序排列线对"<< endl;
    switchBox(8, wirepins2);

    cout<< endl<<"会打架的线对"<< endl;
    switchBox(8, wirepins3);

 
}
