#include<iostream>
#include<memory>
/*
几种初始化方式
std::shared_ptr<int> ptr1(new int);

std::shared_ptr<int> ptr2{new int};

建议make_shared 更高效
std::shared_ptr<int> ptr3;
ptr3 = std::make_shared<int>(100);

std::shared_ptr<int> ptr4{std::make_shared<int>(100)};
*/

struct object
{
    object()  {std::cout<<"创建物体\n";}
    ~object() {std::cout<<"销毁物体\n";}
};

int main()
{
    std::shared_ptr<object> p = std::make_shared<object>();

    std::shared_ptr<object> p1  = p;
    std::shared_ptr<object> p2  = p;

    std::cout<<"使用计数"<<p.use_count()<<std::endl;

    p1.reset();//释放

    std::cout<<"使用计数"<<p.use_count()<<std::endl;

    p2.reset();//释放

    std::cout<<"使用计数"<<p.use_count()<<std::endl;

}