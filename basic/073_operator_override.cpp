// 操作符重载 = 

class MyClass {  //gpt4 回答
    int value;

    // Overload assignment operator
    MyClass& operator=(const MyClass &rhs) {
        // Check for self-assignment
        if (this == &rhs) {
            return *this;
        }

        // Copy the value
        this->value = rhs.value;

        // Return *this to allow chained assignments
        return *this;
    }
};