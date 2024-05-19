//别名的使用方便 模板具象化使用

template<typename T>
struct Stack
{
    // ....
};


void foo(Stack<int> const& s) // parameter s is int stack
{
using IntStack = Stack<int>; // IntStack is another name for Stack<int>
Stack<int> istack[10]; // istack is array of 10 int stacks
IntStack istack2[10]; // istack2 is also an array of 10 int stacks (same type)
//.....
}

//嵌套使用
Stack<Stack<int> > intStackStack; // OK with all C++ version