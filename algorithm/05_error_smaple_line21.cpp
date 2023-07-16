#include<iostream>
#include<vector>
#include "00_he_testTime.cpp"
#include "04_linearlist_chainNode.cpp"
//使用了前面创建的链表  进行箱子排序

using namespace std;

struct  studentRecord
{
   int score = 0;
   const char* name = nullptr  ;

   studentRecord() {cout <<"st默认构造"<<endl;}
   studentRecord(int s, const char* n) {cout <<"st参数构造"<<endl;this->name=n;this->score = s;}
   studentRecord(const studentRecord &st) {cout <<"st拷贝构造"<<endl;score = st.score; name = st.name; }
   //studentRecord(  studentRecord &&st) {score = st.score; name = st.name; }

    studentRecord  operator =(const studentRecord& x) const
    {
       return x; //! 这样乱写是不行的 会导致类传递失败
    }
   bool operator !=(const studentRecord& x) const {return (score != x.score);}
   operator int() const{return score;}
};


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

int main()
{
   chain<studentRecord> ch(10);
   //studentRecord st(3, "lifeng");
    
   //ch.insert(studentRecord(3, "lifeng"));
   ch.push_back(studentRecord(3, "lifeng"));
   ch.push_back(studentRecord(3, "lifeng"));
    
   //! 由于错误的 重载 = 符号 类的类容并没有存入链表 
    
    
    
    

   cout<<ch.size() ;
    
}