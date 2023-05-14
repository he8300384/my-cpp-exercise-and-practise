#include<functional>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
// bind 是用于包裹函数的函数 它是个中介负责存储函数的参数 或者 使得函数形式转化为统一的样式
// 这里演示 通过绑定参数到多参数函数 使得函数变为单参数 在for_each中使用
using namespace std;

struct Pepole {string name; Pepole(string n):name(n){}};

void love(Pepole p1, Pepole p2)  {cout << p1.name << " 喜欢 "<< p2.name << endl; }

int main()
{
    Pepole p1("张三"), p2("王五"), p3("赵四"), p4("吴二");
    vector<Pepole> Pepoles ={p1,p2,p3};

    //把吴二绑定到love函数 遍历列表 使得每个人喜欢他
    //注意bind默认会缓存输入参数 p4会拷贝构造 std::ref 
    for_each(Pepoles.begin(), Pepoles.end(), bind(love,placeholders::_1, std::ref(p4))); //使用ref( )指定参数引用 传递
}


