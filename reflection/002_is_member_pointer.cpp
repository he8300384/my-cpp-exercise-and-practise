#include <iostream>
#include <type_traits>

//判断一个类是否有一个属性

struct my_struct {
    int hello;
    std::string world;
};

int main() {
    bool hasWorldProperty = std::is_member_pointer<decltype(&my_struct::world)>::value;
    
    if (hasWorldProperty) {
        std::cout << "my_struct contains the 'world' property." << std::endl;
    } else {
        std::cout << "my_struct does not contain the 'world' property." << std::endl;
    }
    
    return 0;
}