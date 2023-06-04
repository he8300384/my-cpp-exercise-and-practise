#include<iostream>

class Token
{

};

Token get_token(){};

double expression()
{
    double left = expression();
    Token t = get_token();
}