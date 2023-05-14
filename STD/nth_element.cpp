#include <functional>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    std::vector<int> list {1,3,2,5,66,12,4,6};

    for(auto i:list)  
        std::cout<< i<<"  ";  std::cout<<std::endl;
    int n = 4;
    std::nth_element(list.begin(), list.begin()+n, list.end());

    for(auto i:list)   
        std::cout<< i<<"  ";  std::cout<<std::endl;
    std::cout << "第" << n+1 << "小的元是" << list[n] <<std::endl;    
}