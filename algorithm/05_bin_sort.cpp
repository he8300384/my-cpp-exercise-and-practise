#include<iostream>
#include<vector>
#include "00_he_testTime.cpp"
#include "04_linearlist_chainNode.cpp"
//使用了前面创建的链表  进行箱子排序 期间遇到了类构造 传值问题 莫名其妙又正确了 奇怪

using namespace std;

struct  studentRecord
{
   int score = 0;
   string name   ;

   studentRecord() {cout <<"studentRecord默认构造"<<endl;}
   studentRecord(int s, string n) {cout <<"studentRecord参数构造"<<endl;this->name=n;this->score = s;}
   //studentRecord(const studentRecord &st) {cout <<"studentRecord拷贝构造"<<endl;score = st.score; name = st.name; }
   //studentRecord(studentRecord &&st) {score = st.score; name = st.name;   }
   ~studentRecord(){ }

    studentRecord& operator =(const studentRecord& st)  
    { 
       score = st.score; name = st.name; return *this;
    }
   bool operator !=(const studentRecord& x) const {return (score != x.score);}
   operator int() const{return score;}
};

ostream& operator << (ostream& out, const studentRecord& x)//输出自定义类
{
   out<< x.score << ":" << x.name; return out;
}


void binSort(chain<studentRecord>& theChain, int range)
{
   chain<studentRecord> *bin;
   bin= new chain<studentRecord>[range + 1];//准备一个顺序序列 当桶

   int numberOfElements = theChain.size();
   for(int i = 1; i<= numberOfElements; i++)
   {
      studentRecord x =theChain.get(0);
      theChain.erase(0);
      bin[x.score].insert(0, x);//往桶列表中插入
   }
   
   for(int j = range; j >= 0; j--)
      while (!bin[j].empty())
      {
         studentRecord x = bin[j].get(0);
         bin[j].erase(0);
         theChain.insert(0, x);
      }

   delete [] bin;   
}

//以链表 成员函数方式实现 箱子排序
template<class T>
void chain<T>::binSort(int range)
{
   chainNode<T> **bottom, **top; //双重指针 用于指向 存桶子数组 的节点
   bottom = new chainNode<T> *[range + 1];
   top = new chainNode<T>* [range + 1];

   for(int b = 0; b<= range; b++)   
      bottom[b]= NULL;//箱底设空标志位

   for(; firstNode != NULL; firstNode = firstNode->next)
   {
      int theBin = firstNode->element;
      if(bottom[theBin] == NULL)
         bottom[theBin] = top[theBin] = firstNode;
      else
         top[theBin]->next = firstNode;
         top[theBin] = firstNode;   
   }    

   chainNode<T> *y = NULL;
   for(int theBin = 0; theBin <= range; theBin ++)
      if(bottom[theBin] != NULL)
      {
         if(y == NULL)
            firstNode = bottom[theBin];
         else
            y->next = bottom[theBin];
         y= top[theBin];   
      }  
   if(y != NULL)
         y->next = NULL;
   delete [] bottom;
   delete [] top;
}

int main()
{
   chain<studentRecord> ch(10);
     
   ch.push_back(studentRecord(3, "aaa"));
   ch.push_back(studentRecord(4, "bbb"));
   ch.push_back(studentRecord(3, "ccc"));
   ch.push_back(studentRecord(6, "ddd"));
   ch.push_back(studentRecord(2, "sss"));
   ch.push_back(studentRecord(2, "xxx"));
   ch.push_back(studentRecord(1, "yyy"));
   ch.push_back(studentRecord(5, "zzz"));
   ch.push_back(studentRecord(0, "rrr"));  

   //binSort(ch, 6); //外部函数

   ch.binSort(6);    //成员函数

   ch.output();  
}