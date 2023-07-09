#include <iostream>
#include <functional>
#include <ctime>
 
#include <algorithm> //copy
 

using namespace std;

template<typename T>
void used_time(function<T> func , int times)
{
    //int a[1000], step = 10;
    double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000;
    cout<<"运行 " <<times << "次 时间是: ";

clock_t startTime = clock();
for(int n= 0; n<=times; n+=1)
{      
    func();     
}
  double elapsedMillis = (clock() - startTime)/ (double) CLOCKS_PER_SEC  ;
 cout << elapsedMillis << endl;
}


template<typename T>
void used(function<T> func)
{
    func();
}

void p(){cout<<"hi\n";}
 
// int main()
// {
    // function<void()> pp = p;
    // used(pp);
    // used_time(pp);
// }