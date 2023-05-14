#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
//延时排序 只对选择区域排序 以优化运行速度

template< typename Begin, typename End, typename Mid>
void lazy_sort(Begin begin, Mid mid,  End end)
{
    //中位元素分切列表 使得左边全小于它 右边全大于它
    std::nth_element(begin, mid, end); 
    //对左边排序
    std::sort(begin, mid);
}

int main()
{
    std::vector<int> list {3, 1, 4, 11, 5, 12, 33, 2, 6, 7, 8};
    for(auto i:list)  
        std::cout<< "原列表"<< i <<"  ";  std::cout<<std::endl;
     
    lazy_sort(list.begin(),list.begin() + 2, list.end()); 

    for(auto i:list)  
        std::cout<< "前端 排序后 "<< i<<"  ";  std::cout<<std::endl;
}