#include<iostream>

/*
覆写 new delete 函数目的

    1 追踪错误 内存泄漏
    2 优化内存分配
    3 收集 使用状态 数据
*/

/*
注意 4 个函数
    new      分配内存   构造对象 
    原型 1 void* operator new  (std::size_t size);   书写形式 new Type(args)         实际调用 operator new(sizeof(Type))
    原型 2 void* operator new[](std::size_t size);   书写形式 new Type[]{初始化列表}  实际调用 operator new(sizeof(Type) * n)

    delete   析构对象   释放内存、
    原型 3 void* operator delete  (void* ptr) noexcept;   书写形式 delete   ptr      实际调用 operator delete(ptr)
    原型 4 void* operator delete[](void* ptr) noexcept;   书写形式 delete[] ptr      实际调用 operator delete(ptr)

    以上 4 个函数可以被 覆写

    malloc 分配失败 返回 nullptr
    new 分配失败 抛出 std::bad_alloc
*/

//AAAA 全局重载！ 这是被重新定义的 new  一般不去覆盖全局new
void* operator new(std::size_t size)
{
    if(size == 0)
        size = 1;
    while(true)
    {
        if(auto ptr = std::malloc(size))
        {
            std::cout<<"分配 地址："<<ptr<<" 大小"<<size <<std::endl; //! 可以记录到 各种地方
            return ptr;
        }
        auto handler = std::get_new_handler();
        if(handler)
            handler();
        else
            throw std::bad_alloc();
    }
}

//BBBB  全局重载！ 这是被重新定义的 delete 一般不去覆盖全局delete
void operator delete(void* ptr) noexcept
{
    if(ptr == nullptr)
    {
        std::cout<<"释放失败\n";
        return;
    }
    std::free(ptr);
    std::cout<<"删除 地址："<<ptr<<" 被释放" <<std::endl; //! 可以记录到 各种地方
}



//CCCC   在类中覆写 是更常用的
// 注意两点 1 new 构建类 会优先找类中的 new
//         2 使用 ::new 会调用全局的new
class Myclass
{
public:
    static void* operator new(std::size_t size, int a) //static 不写 也是static的
    {    
        std::cout<< "调用了 Myclass new";
        std::cout<< " 附加了参数:" << a <<std::endl ;
        return  ::operator new (size);
    }

    void operator delete(void* ptr) 
    {
        std::cout << "调用了 Myclass delete\n";
        ::operator delete(ptr);
    }
};

int main()
{
    int* ip  = new int ;        //自动计算 分配一个int 空间  等同于  int* p = （int*）malloc(sizeof(int) * 10)
    delete ip;

    char* ip2  = new char ;        //自动计算 分配一个int 空间  等同于  int* p = （int*）malloc(sizeof(int) * 10)

    int* ips = new int[10] ;    //分配 10个 int 的数组空间
    delete [] ips;              //销毁注意加【】

    Myclass* m = new(1) Myclass  ;//! 注意 平时没有参数就是一个呢哇 如果多出的参数要卸载括号内
                                 //常用 是 Myclass* m = new(给定地址) Myclass 用给定地址构造对象 叫做 placment new
    delete m;
    delete m;
}