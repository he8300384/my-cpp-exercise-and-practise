#include <iostream>
#include <vector>
#include <algorithm>  
#include <hash_map>
#include <cstring>

using namespace std;


// lzw 压缩编码算法 

struct  dictinary 
{
   char** seq;//字母组合序列
   int* code; //编码序列
   int size;
   int maxSize;
};

void insert_seq(dictinary& dict, char*seq){
    int i = dict.size;
    dict.seq[i] =  new char ;
    dict.code[i] = i;
    dict.size++;
     strcpy(dict.seq[i], seq);
}

void init_dictionary(dictinary & dict, int maxSize){
    dict.maxSize = maxSize;
    dict.size = 0;
    dict.seq =  new char*[maxSize];
    dict.code = new int  [maxSize] ;

    insert_seq(dict, "#");
    char seq[2] = "A";
    for(int i =0; i<26; i++)
    {
        insert_seq(dict, seq);
        seq[0]++;
    }
}

void print_dictionary(dictinary& dict){
    cout<< "打印码表字典"<<endl;
    for(int i =0; i< dict.size; i++)
        {
            cout<< dict.code[i]<< "     ";
            cout<< dict.seq [i]<< " ";
            cout<< endl;
        }
}

int get_seq_code(dictinary& dict, char* seq)
{
    for(int i = 0; i< dict.size; i++)
        if(!strcmp( dict.seq[i], seq))
            return i;
    return -1;        
}


//! lzw 编码
void LZW_encode(char* text, dictinary& dict)
{
    char current[1000];
    char next;
    int code;
    int i = 0;
    while(i< strlen(text))
    {
        sprintf(current,"%c", text[i]); //存字符到缓冲区
        next = text[i + 1];
        if(next =='\0'){ break; }
        while(get_seq_code(dict,current) != -1)
        {
            sprintf(current, "%s%c", current, next);      
            i++;
            next = text[i+1] ;
        }
        current[strlen(current) - 1]='\0'; //裁掉最后一位 无效探测位
        next = text[i];
        code = get_seq_code(dict, current);
        sprintf(current, "%s%c", current, next);
        insert_seq(dict, current);
     // cout << code <<" "<< current<<endl ;
    }

}
void LZW_decode()
{
    
}

int main()
{
    dictinary dict;
    init_dictionary(dict, 256);
    //print_dictionary(dict);
    //cout << get_seq_code(dict, "C");

    LZW_encode("TOBEORNOTTOBEORTOBEORNOT", dict);//实验将一组字符串编码
    
    print_dictionary(dict);

}