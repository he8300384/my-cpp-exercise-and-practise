#include<vector>


//1. Pass by Value: This creates a copy of the vector in the function. Any changes made inside the function will not affect the original vector.
void function(std::vector<int> vec) 
{
    // vec is a copy of the original vector
} 


//2. Pass by Reference: This passes the original vector itself to the function. Any changes made inside the function will affect the original vector.
void function(std::vector<int>& vec) 
{
    // vec is the original vector
} 


//3. Pass by Constant Reference: This passes the original vector to the function, but prevents the function from modifying it. This is useful when you want the efficiency of passing by reference but don't want the function to change the vector.
void function(const std::vector<int>& vec) 
{
    // vec is the original vector, but cannot be modified
}