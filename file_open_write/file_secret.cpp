#include <fstream>
#include <iostream>
#include <string>

//BUG 还原的文件尾部多个 ? 号
int main(int arge, char* argv[])
{
    std::ifstream open_file;
    open_file.open(argv[1],std::ios::in | std::ios::binary);//拖拽读取文件

    std::ofstream creat_file;
    creat_file.open("test.txt",std::ios::out  | std::ios::binary );
    
    std::cout<< open_file.is_open() << " " << creat_file.is_open() << std::endl;

    if(!open_file.is_open()) return 0;
    if(!creat_file.is_open()) return 0;

    char buffer; //单字节存储

 //单字节读取    
 while(!open_file.eof())
    {
        buffer = open_file.get();//获取单字节
        
        std::cout<<buffer; 

        buffer ^=  0x66  ; //异或修改加密

        creat_file.write(&buffer, 1) ;//拷贝单字节
        //creat_file << buffer; 可这样写
     
    }       

    open_file.close();
    creat_file.close();
    //std::cout<< "presh any key to close\n";
    //getchar();
}