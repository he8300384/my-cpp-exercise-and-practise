#include <iostream>
#include <vector>
#include <algorithm>  
#include <stack>  

//使用栈 求解迷宫
//书上程序较为晦涩 我这用了直白的方式 虽然罗嗦了点
//用了极其简单的int 表示迷宫和路径 很多变量写死方便实验

//1 用墙围好迷宫
//2 从入口开始 入栈节点 
//3 本节点是出口 寻找成功
//4 堵上本节点防止无限巡回
//5 上下左右寻找空格 
//6 如果没有出路 退栈本节点
//7 如果有出路  移动到出路 入栈出路节点
//8 判定栈空 寻找失败    
using namespace std;

struct Position
{
    int x; int y;
    Position(int xx, int yy):x(xx),y(yy){}
    Position left (){return Position(x -1,  y);}
    Position right(){return Position(x +1,  y);}
    Position up   (){return Position(x  , y-1);}
    Position down (){return Position(x  , y+1);}
    bool operator ==( Position const& p){return (p.x == x)&&(p.y == y);}
    Position& operator =( Position const& p){  p.x == x; p.y == y; return *this;}
};

ostream& operator<<(  ostream& out,const Position& p ){out <<"(" << p.x << "," << p.y <<") "; return out;}

struct Maze{
    //写死的迷宫大小
   int maze[7][7] =   {{1, 1, 1, 1, 1, 1, 1},
                       {1, 0, 1, 0, 1, 0, 1}, 
                       {1, 0, 1, 0, 1, 0, 1}, 
                       {1, 0, 1, 0, 0, 0, 1}, 
                       {1, 0, 1, 0, 1, 0, 1}, 
                       {1, 0, 0, 0, 1, 0, 1}, 
                       {1, 1, 1, 1, 1, 1, 1}};
                                                                                                 
    void findPath()
    {
        int Maze[7][7];
        memcpy(Maze, maze, sizeof(maze)); 
        
        Position in (1,1);
        Position out(5,1);
        int steps = 0;
        stack<Position> path;

        path.push(in);

//! 核心寻路逻辑
        while(true)
        {
            steps += 1;

            if(path.empty()){cout <<"经历"<< steps << "步没找到终点\n";break;}
               
            Position here = path.top();

            Maze[here.y] [here.x] = 1 ;//堵走过的路 防止遍历回来

            if(here == out) 
            {
                cout <<"\n经历 "<< steps << "步寻找 路线如下 ";     
                showPath(path);
                break;
            }

            if( !(Maze[here.left().y] [here.left().x]) )   // 式左边
            {
                path.push(here.left()); continue ;
            }
                      
            if( !(Maze[here.up().y] [here.up().x]) )       // 式上边
            {
                path.push(here.up()); continue ;
            }
             
            if( !(Maze[here.right().y] [here.right().x]) )  // 式右边
            {
                path.push(here.right()); continue ;
            }

            if( !(Maze[here.down().y] [here.down().x]) )   // 式下边
            {
                path.push(here.down()); continue ;
            }   

            else //没式出路 弹出这个节点
                 
                path.pop();
            
        }
    }  

    void showPath(stack<Position>& s)
    {
        int maze[7][7] = {0};
        while(!s.empty())
        {
            maze[s.top().y ][s.top().x] = 1 ;
            s.pop();
        }
         for(int i = 0; i< 7; i++)
        {
           cout<< endl;
           for(int j = 0; j< 7; j++)
               cout<<maze[i][j]<<"  ";
        }  
        cout<< endl;                           

    }           
                         
    void output()
    {
         cout << "原始迷宫如下\n";   
         for(int i = 0; i< 7; i++)
         {
            for(int j = 0; j< 7; j++)
                cout<<maze[i][j]<<"  ";
            cout<< endl;    
         }  
        cout<< endl;                           
    }
};

int main()
{
    Maze m;
    m.output();
    m.findPath();
}

                          