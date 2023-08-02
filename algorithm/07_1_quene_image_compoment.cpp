#include <iostream>
#include <vector>
#include <algorithm>  
#include <queue>
 

//类似与迷宫问题
//识别像素属于哪个物体

using namespace std;
 
struct Position
{
    int x; int y;
    int compomentClass = 0; //用于识别像素的类别
    Position(int xx, int yy):x(xx),y(yy){}
    Position left (){return Position(x -1,  y);}
    Position right(){return Position(x +1,  y);}
    Position up   (){return Position(x  , y-1);}
    Position down (){return Position(x  , y+1);}
    bool operator ==( Position const& p){return (p.x == x)&&(p.y == y);}
    Position& operator =( Position const& p){  p.x == x; p.y == y; return *this;}
};

ostream& operator<<(  ostream& out,const Position& p ){out <<"(" << p.x << "," << p.y <<") "; return out;}


struct Image{
    //写死的图像大小
   int image[7][7] =  {{0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 0, 1, 1, 0}, 
                       {0, 0, 1, 0, 1, 0, 0}, 
                       {0, 1, 0, 0, 0, 1, 0}, 
                       {0, 1, 1, 0, 1, 1, 0}, 
                       {0, 1, 1, 0, 1, 1, 0}, 
                       {0, 0, 0, 0, 0, 0, 0}};

    void seek4direction(queue<Position> &path, int kind)
    {   

        Position here = path.back();
         
        image[here.y][here.x] =  kind;
    
        
        if((image[here.left().y] [here.left().x]) == 1)    // 式左边
        {      
            path.push(here.left());  
            seek4direction( path, kind) ;
        }
    
        if((image[here.up().y] [here.up().x])   == 1)       // 式上边
        {
            path.push(here.up());  
            seek4direction(path, kind) ;
        }
    
        if((image[here.right().y] [here.right().x]) == 1)  // 式右边
        {
            path.push(here.right()) ;   
            seek4direction(path, kind) ;
        }
        if((image[here.down().y] [here.down().x]) == 1)   // 式下边
        {
            path.push(here.down());  
            seek4direction(path, kind) ;
        }       
         return;
    }
                                                                                             
    void findCompoments()
    {                  
        int kind = 2;
        queue<Position> compoments; //用于存储识别到的图元的顺序队列 所有种类顺寻叠放在一起的

        //! 核心逻辑
//遍历图像像素
        for(int i=0; i<7; i++)
            for(int j=0; j<7; j++)
            {
                if(image[i ][j ] == 1) //发现有像素开始处理像素
                {
                   Position pixel(j,i);//判断当前像素
                   pixel.compomentClass = kind;
                   compoments.push(pixel);
                   seek4direction(compoments, kind); //! 递归求解本像素邻接像素
                   kind ++;
                }    
            }
        cout<<"图元标记完毕\n";    
    }  
                        
    void output()
    {
         cout << "图像现在情况如下\n";   
         for(int i = 0; i< 7; i++)
         {
            for(int j = 0; j< 7; j++)
                cout<<image[i][j]<<"  ";
            cout<< endl;    
         }  
        cout<< endl;                           
    }
};

int main()
{
   Image m;
   m.output();
   m.findCompoments();
   m.output();
}

                          