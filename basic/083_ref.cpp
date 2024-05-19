#include <iostream>
#include <functional>

void Add(int& x) {
    x++;
}

int main() {
    int num = 5;
    
    std::cout << "函数调用前: num =  " << num << std::endl;
    
    std::reference_wrapper<int> numRef = std::ref(num); //创建一个引用  引用一个值 

    Add(numRef); //使得传递引用的函数可以使用这个值的引用
    
    std::cout << "函数调用后: num =  " << num << std::endl;
    
    return 0;
}