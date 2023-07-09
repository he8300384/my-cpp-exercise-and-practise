#include <memory>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int p[10] = {1,2,3,4,5,6,7,8,9,10}; 

    copy(p+1,p+10, p); //拷贝数组片段到指定位置    参数全是指针

    for(auto i:p)
        cout<< i<< " ";    
}