#include <fstream>
#include <iostream>
#include<sstream>

void openFile(const char* l1, const char* l2)
{
     std::string  vertexCode;
 std::string  fragmentCode;
 std::ifstream vShaderFile;
 std::ifstream fShaderFile;        
 
 vShaderFile.open(l1 );
 std::cout <<l1 << vShaderFile.is_open() << std::endl;
 if( vShaderFile.is_open() == false) //判断打开失败与
 std::cout<<"vertexshader open failed\n"; 
 
 fShaderFile.open(l2);
 std::cout <<l2<<fShaderFile.is_open() << std::endl;
 if( vShaderFile.is_open() == false) //判断打开失败与
 std::cout<<"fragmentshader open failed\n"; 


 std::stringstream vShaderStream, fShaderStream;
 vShaderStream << vShaderFile.rdbuf();
 fShaderStream << fShaderFile.rdbuf();
 vShaderFile.close();
 fShaderFile.close();
 vertexCode = vShaderStream.str();
 fragmentCode = fShaderStream.str();
std::cout<<vertexCode<<std::endl;
std::cout<<fragmentCode<<std::endl;
}

int main()
{
    openFile("shader\\shader.fs", "shader\\shader.vs");
    std::cout<<"opened\n";
}
