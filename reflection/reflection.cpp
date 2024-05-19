#include <string>
#include <iostream>

#define REFLECT(x) template<class R> void reflect(R& r) { r x; }

struct Employee 
{
    std::string emp_id;
    int salary;
REFLECT(("Emp_id", emp_id) ("Salary", salary))
};


class Demo {
    std::ostream& output;
    bool flag;
    public:
    Demo(std::ostream& output) : output(output){}

template<class T>
auto write(T& myobj) -> decltype(myobj.reflect(*this), void()) 
{
    output << "{";
    flag = false;   
    myobj.reflect(*this);
output << "}\n";
}
void write(int val) 
{
    output << val;
}
void write(std::string& val) 
{
    output << '"' << val << '"';
}

template<class T>
Demo& operator()(const char* emp_id, T& myfield) {
if (flag) {
output << ",";
}
flag = true;
output << emp_id << ":";
write(myfield);
return *this;
}
};

int main() {
Demo myObj(std::cout);

Employee emp1 = { "2324354", 90000 };
myObj.write(emp1);
Employee emp2 = { "235566", 50000 };
myObj.write(emp2);
}