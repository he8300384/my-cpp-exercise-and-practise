#define _CRT_SECURE_NO_WARNINGS //不跳出c函数 安全警告

#include<iostream>
#include<string.h>

using namespace std;

char* copy_char(const char* c)//分配堆区址 拷贝数据
{   
    
    char* dup = new char[100];
    strcpy(dup, c); 
    return dup;
}

bool find_char(const char*s,  char  x)
{
    for(int i=0; i<strlen( s); ++i)
    {
        cout<< s[i] << " "<< endl;
        if (s[i] ==  x)
        {
            cout << i <<endl;
            return 1;
        }       
    }  
      return 0;     
}

int str_len(const char* p) //字符数组无法知道长度 但可以用 0 结尾判断长度 这是类似 strlen() 的实现
{
    int n = 0;
    while(p[n]) ++n;
    return n;
}

void arrayOut(int a[], int len) //必须传入数组长度 函数内部计算sizeof(a) 只会是 *int 4字节
{
	for(int i; i<len;i++)
	{
		cout << a[i] << "  ";
	}
	cout <<endl;
}

int main()
{
    char a[10] = "adffasd11";  
    char b[10] ={0}  ;      //初始化不要忘记
    strcpy(b,a);
    cout << b << endl;

    int c;
    //int lis[c]; //不能用常量

    char d[10] ={0}  ;
    strncpy(d,a,3); //注意一旦有截取结尾0就消失 所以全员清0很必要
    cout << d << endl;
    
    char* cc= copy_char("vdsfafadsfafds");
    cout <<"字符" <<  cc <<endl;
    delete[] cc;

    bool   s= find_char("afafds",'d');
    cout <<  s << endl;

    const char* cccc = "sdfadsfasf";
    cout << cccc[2] << " " << strlen(cccc) << endl;

    cout << str_len("asdf") <<endl;
}