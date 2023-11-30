// c++ 默认宏  https://learn.microsoft.com/zh-cn/cpp/preprocessor/predefined-macros?view=msvc-170

//#号 转换变量为字符
#define PRINT(x) std::cout<<#x<<std::endl; 

#include <iostream>

using namespace std;

void fuc(){cout <<  __func__  << endl;} //输出函数名字

int main()
{
    PRINT(hi);

    cout << __LINE__ <<"  "<< __TIME__ << __DATE__ << __FILE__ << endl;
    fuc();
}