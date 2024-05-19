#include <string_view>
#include <iostream>
#include <string>

//string view 用于直接访问字符串地址内容 它就是一个指针和 访问长度   高效！！
//可以从string const char* 隐式转换   可显式转换为string    可以放入容器 

void fun(std::string_view str) 
{  
    std::cout << str << std::endl;
}

int main()
{   
    std::string_view stw = "测试";
    std::cout<<stw<<std::endl; //这里直接访问字符区内容 中间不构造类



    std::string str = "abcdefghijk";
    std::string_view st = str.substr(0 ,2); 
    std::cout<<st<<std::endl; //这里直接访问切片内容 中间不构造类

    

    fun("原封不动看");// 中间不会构建string 类实例 本质就是指针访问
}