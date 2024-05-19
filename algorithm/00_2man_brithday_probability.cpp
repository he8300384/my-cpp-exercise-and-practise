#include<iostream>

using namespace std;

int main()
{
    float not_sameday_probablility = 1.0;

    //一次放入屋子一个人 两人生日不在一天概率 放n个人后
    for(float n = 2.0; n<60.0; n++)
    {
        float newfactor = (365 - (n - 1))/365;
        not_sameday_probablility *=newfactor;
        //cout << not_sameday_probablility;
    }
    cout << 1 - not_sameday_probablility; //同一天生日概率 结果0.507297
}