#include <iostream> 
#include <reflect> 
#include <vector>  
struct Person {   std::string name;   int age;   double height; }; 
REFLECT(Person, name, age, height);  

int main() {
       Person p = {"Alice", 25, 168.5};   
for (const auto& member : reflect<Person>().members) 
{     std::cout << member.name << " = " << member.get(p) << std::endl;   }   
return 0; }

 