#include<iostream>
#include<initializer_list>

using namespace std;

double sum(std::initializer_list<double> i)
{
    double total = 0;
    for(auto ii =i.begin(); ii !=i.end(); ii++)
     total  += *ii;

    return total;
}

int main(){
    double total = sum({3.2, 1.3, 22.2, 3});
    cout << total <<endl;
}