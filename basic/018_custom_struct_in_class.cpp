//类中内嵌结构体 可以屏蔽外界直接方问它 只能通过实例属性访问

class MyClass 
{
public:
    struct MyStruct {
        int x;
        float y;
    };

    MyStruct s;
};

int main()
{
    MyClass obj;
    obj.s.x = 10;
    obj.s.y = 20.5;
    
}