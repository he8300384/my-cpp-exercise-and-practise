#include <iostream>
#include <type_traits>

template <typename T, typename U>
void convertCheck(T t, U u) {
    if constexpr (std::is_convertible<T, U>::value) {
        std::cout << "Conversion from T to U is possible." << std::endl;
    } else {
        std::cout << "Conversion from T to U is not possible." << std::endl;
    }
}

int main() {
    convertCheck(10, 3.14); // Check if int can be converted to double
    convertCheck(3.14, "aa"); // Check if double can be converted to int
    return 0;
}