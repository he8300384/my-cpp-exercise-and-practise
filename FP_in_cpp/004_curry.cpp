//c++ 柯里化

#include <functional>
#include <iostream>

using namespace std;

template<typename Func, typename... Args>
auto curry(Func func, Args... args)
{
    //值捕获所有参数
    return [=](auto... p){ return func(args..., p...); };     
}

int area(int len, int wid){return len*wid;}

auto main() -> int
{
    auto len5 = curry(area, 5);
    for(int i = 0; i < 5; ++i)
        cout<< "边长5 x 宽度"<< i << " = 面积 " << len5(i) << endl;
}