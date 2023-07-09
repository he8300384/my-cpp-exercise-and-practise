//new 和 delete 是c++ 对应 c 的 malloc free
//new 是对象

#include<iostream>

using namespace std;

//创建队堆空间 注意这个函数不负责释放
int* creat(int size)
{
   int* p = new int[size];
   return p;
}

//使用对象的生命周期可以自动回收空间
//可以定义各种使用行为
struct mylist
{
    int* p;
    int msize;
    int mlistSize;
    
    mylist(int size){ 
        p = new int[size]; 
        msize=size;
        initlist();
        }
    ~mylist(){ delete[] p; p=nullptr; }
    int operator[](const int index)const
    {
        return p[index];
    }

    void output()
    {
        for(int i=0; i<mlistSize;i++){cout<<p[i]<<" ";}
    }

    void initlist()
    {
        for(int i=0; i<msize;i++){ p[i]=0;}
        mlistSize = 0;
    }
    //重新找空间
    void resize(int size) 
    {
        int* newspace = new int[size]; 
        copy(p, p+msize, newspace);
        delete[] p;
        msize =size;
        p = newspace;
        cout << "重新分配空间大小："<<size<<endl; 
    }

    int size(){return  mlistSize;}

    void push_back( int i)
    {
        if(mlistSize == msize){resize(msize*2);}
        p[mlistSize] = i;
        mlistSize++;
    }
};

int main()
{
    int* p = creat(10);
    p[0] = 12; p[1] = 13; p[3] = 14;
    cout <<  p[1];
    delete[] p; //删除p指向的堆内容
    p=nullptr;//p指向区域内容已经销毁  把它指向空
    cout<< endl;
    
    mylist c(3);
     
    for(int i=0; i<100000;i++)
        c.push_back(i); 

    //c.output();
    cout<< endl;
     
    cout<<"列表长度: "<< c.size() <<"   可用空间大小: "<< c.msize;
    
}