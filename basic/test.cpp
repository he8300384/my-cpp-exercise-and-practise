#include <typeinfo>
#include <iostream>

class MyClass {
public:
    int myInt;
    float myFloat;
    std::string myString;

    void myFunction() {
        // Function body
    }
};

int main() {
    MyClass obj;

    // Get the type information for MyClass
    const std::type_info& info = typeid(obj);

    // Print the name of the class
    std::cout << "Class name: " << info.name() << std::endl;  

    // Iterate over the members of the class
    for (auto member : {"myInt", "myFloat", "myString", "myFunction"}) {
        // Get the type information for the member
        const std::type_info& member_info = typeid(obj.*(&MyClass::myInt));

        // Print the name and type of the member
        std::cout << "Member name: " << member << ", type: " << member_info.name() << std::endl;
    }

    return 0;
}