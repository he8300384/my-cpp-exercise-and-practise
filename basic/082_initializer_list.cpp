#include <iostream>
#include <initializer_list>

//初始化列表 传递值

void printValues(std::initializer_list<int> values) {
    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    printValues({1, 2, 3, 4, 5});
    return 0;
}