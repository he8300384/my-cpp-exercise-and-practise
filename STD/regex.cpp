#include<regex>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
//正则表达式 shiyan

int main()
{
    regex pattern;
    string pat;
    cout <<"输入正则模式: ";
    getline(cin, pat);
     
    try{
        pattern = pat;
        cout <<"pattern: "<< pat <<"\n";
    }

    catch(bad_exception){
        cout << pat << "is not a valied regula expression\n";
        exit(1);
    } 

    cout << "输入匹配测试行: \n";
    int lineno = 0;

    for(string line; getline(cin, line);){
        ++lineno;
        smatch matches;
        if(regex_search(line, matches, pattern)){ //搜索匹配
            cout << "line" <<lineno << ":" <<line << "\n";
            for(int i=0; i< matches.size();++i)
                cout <<"\t找到匹配行[" <<i<< "]"<<line    // \t制表符
                     << matches[i] <<"\n";
        }
        else
            cout <<"不匹配\n";
    }
    return 0;
}