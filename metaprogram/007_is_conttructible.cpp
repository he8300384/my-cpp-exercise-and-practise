#include <iostream>
#include <type_traits>
#include <vector>

template <typename T, typename... A>
void constructCheck() {
    if constexpr (std::is_constructible<T, A...>::value) {
        std::cout << "Type T is constructible with Args." << std::endl;
    } else {
        std::cout << "Type T is not constructible with Args." << std::endl;
    }
}

int main() 
{
    constructCheck<int, double>(); // Check if int can be constructed with a double
    constructCheck<std::string, double>(); // Check if std::string can be constructed with a const char*
     
}  