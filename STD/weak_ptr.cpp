#include<iostream>
#include<memory>

//配合 shared ptr 避免循环依赖 导致资源无法释放
//用share 创建对象 week接管 处理对象 销毁 一键clear 

struct object
{
    int ID = 1;
    object()  {std::cout<<"创建物体\n";}
    ~object() {std::cout<<"销毁物体\n";}
};

int main()
{
    std::weak_ptr<object> wp, wp1;
    std::shared_ptr<object> sp{std::make_shared<object>()};
    wp = sp;
    auto resource = wp.lock();//访问对象
    if(resource)
        std::cout<<"物体ID： " << (*resource).ID <<std::endl;

    std::cout<<"引用计数 " << resource.use_count() <<std::endl;

    sp.reset();
    
    std::cout<<"引用计数 " << resource.use_count() <<std::endl;
}