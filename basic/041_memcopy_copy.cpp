#include<iostream>
#include<algorithm>
#include<vector>  
//#include<string>
using namespace std;

int main()
{


//In C++, you can use std::copy and std::memcpy to copy elements from one container to another.  

//std::copy is a standard algorithm that works with all containers and types that support assignment. It's safer and more versatile.

std::vector<int> src = {1, 2, 3, 4, 5};
std::vector<int> dest(src.size());

std::copy(src.begin(), src.end(), dest.begin());




//std::memcpy is a C library function that copies a block of memory from one location to another. 
//It's faster but less safe, because it doesn't call constructors or handle object ownership. It should only be used with trivially copyable types.

int src2[5] = {1, 2, 3, 4, 5};
int dest2[5];

std::memcpy(dest2, src2, sizeof(src2));

}




























 
 
