#include <iostream>

class myFlie 
{
public:
     FILE* m_file = nullptr;
     myFlie(const char* filePath)
     {
        if((m_file = fopen(filePath,"w")) == 0)
            std::cout << "file open failed\n";
     }
     ~myFlie()
     {
        if((fclose(m_file)) != 0)
            std::cout << "file close failed\n"; 
     }
     
     void add(char c)
     {
        if(m_file != nullptr)
            fputc(c, m_file);
     }
};



int main()
{
    std::cout<< " hello world" << std::endl;
    myFlie file("test.txt");
    file.add('c');
    file.add('b');
    return 0;
}