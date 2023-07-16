#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

template<class T> 
class mystack // 抽象基类
{
    public:
    virtual ~mystack(){}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& top() = 0;
    virtual void pop() = 0;
    virtual void push(const T& theElement) = 0; 
};

//书上用了多继承 数组线性表 我这里直接使用vector实现 不那么啰嗦 很简陋 只是用来

template<class T>
 class vectorStack:public mystack<T>
 {
    vector<T>* element;
    public:
    ~vectorStack(){delete element;};
    vectorStack(int initSpace = 1) {element =new vector<T>(initSpace);}
    bool empty() const {return element->empty();}
    int  size()  const {return element->size(); }
    void clear() {element->clear();}
    T& top()
    {
        if( element->empty()){cout<< "no element on top\n" ;}
        return   (*element)[element->size()-1]   ;
    }

    void pop()
    {
        if( element->empty()){cout<< "no element to pop\n";return;}
        element->pop_back();
    }

    void push(const T& theElement)
    {
        element->push_back(theElement);
         
    }

    void output() const
    {
        for(auto i: *element) 
            cout << i << " ";
    }
    
 };

//递归解汉诺塔 ——————————————————————————————————————————————————————
 void doMove(int start,int end) //实际移动操作
 {
    cout << start << " -> " << end << endl;
 }

 void hanoi(int hight,int start,int end)
 {
    if(hight == 1) //递归到单个碟子才有可能移动
        doMove(start, end);
    else      
    {     //这个部分用于递归出移动的起始杆子和终点杆子
        int other = 6 - (start + end); //计算目标移动杆子 比如 1 3 就 移到 2
        hanoi(hight-1, start, other);  //将堆底以上 递归的移到另一杆子
        doMove(start, end);            //将堆低移到最后一个杆子
        hanoi(hight - 1, other ,end);  //完成底部最大一块移动 递归的继续移动剩下的
    }    
 }

//栈解汉诺塔 ——————————————————————————————————————————————————————
//有错误 怎么数组2号 表示的3号桩 还有忽视输出的0 那是自定义栈的bug
vectorStack<int> tower[4];  
 void moveAndShow(int n, int x, int y, int z)
 {
     if(n > 0)
     {
        moveAndShow(n-1, x, z, y);
        int d= tower[x].top();
        tower[x].pop();
        tower[y].push(d);

        tower[1].output();cout<<"\t\t|"; tower[3].output();cout<<"\t\t|";tower[2].output();
        cout << endl;
        moveAndShow(n-1, z, y, x);
         
     }
 }

  void towersOfHanoi(int n)
 {
     for(int d = n; d > 0; d--) //装载 圆盘
         tower[1].push(d);

    tower[1].output();cout<<"\t|"; tower[3].output();cout<<"\t\t|";tower[2].output();
    cout << endl;

     moveAndShow(n, 1, 2, 3);    
 }

 

int main()
{
    cout << "函数递归方法  --------------------- " << endl << endl;
    hanoi(3 , 1, 3);
    cout << endl<< endl << "栈方法  --------------------- " << endl ;
    towersOfHanoi(3);
}