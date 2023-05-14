#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
//延时排序 只对选择区域排序 以优化运行速度

std::vector<unsigned int> cache {0, 1};

unsigned int fib(unsigned int n)
{
    if  (cache.size() >n) {std::cout<<"读取缓存\n"; return (cache[n]);}
    else {
        const auto result = fib(n-1) + fib(n-2);
        cache.push_back(result);
        std::cout<<result<<" 结果存入缓存\n";
        return result;
    }
}

int main()
{
    fib(22);
}