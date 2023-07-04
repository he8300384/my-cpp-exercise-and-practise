#include<iostream>
#include<vector>

using namespace std;



//分治算法排序  

//工具函数 求左右部分 
template<typename T>
vector<T> left(vector<T> A)
{      
    if(A.size() == 1) return vector<T>(0);    
    return vector<T>(A.begin(),A.begin() + A.size()/2);
}   

template<typename T>
vector<T> right(vector<T> A)
{          
    return vector<T>(A.begin() + A.size()/2,A.end());    
}

//合并两个 已经排序的序列 成为有序的大序列
template<typename T>
vector<T> merged(vector<T> Left,vector<T> Right )
{   
    int L = Left.size()  , R = Right.size()  ;
    int size =  L + R ;
    int l=0, r=0;
    vector<T> merged ;
    for(int i = 0; i <size  ; ++i)
    {
        if(l == L  ){ //左侧抽选完毕 直接抽选右边           
            merged.push_back(Right[r]);
            ++r;
            continue;
        }
        if(r == R  ){ //右侧抽选完毕 直接抽选左边            
            merged.push_back(Left[l]);
            ++l;
            continue;
        }
 
        if(Left[l] < Right[r]  ){
            merged.push_back(Left[l]);
            ++l;
        }

        if(Left[l] >= Right[r]  ){
            merged.push_back(Right[r] );
            ++r;
        }
    }
    return merged;
}


//todo BUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUG
template<typename T>
vector<T> divide_conquer_sort(vector<T> A )
{  
    vector<T> Left =  divide_conquer_sort(left (A)); //递归左侧                          
    vector<T> Right=  divide_conquer_sort(right(A)); //递归右侧 

    if(Left.size() == 0) //最底层只有单一元素 时返回元素本身  Right 就是其本身
        return  Right;
                                                                           
    return merged(Left, Right);                                         
}
          

int main()
{
    vector<int> v{3,1,2,4,6,2,3,1,6 };
    vector<int> v3{5     };
    vector<int> v4{1  };

    vector<int> v2 = merged (v3, v4);  //! 已经排序的子序列合并成一个有序序列
    //vector<int> v55 = divide_conquer_sort (v ); //todo BUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUGBUG

    for(auto i: v2)
        cout << i << " ";
      cout <<endl;
    // vector v2(v.begin(), v.begin() + v.size()/2); 
     //merge2 (v3,v4 );
// 
    vector<int> v11 = left (v);
    for(auto i: v11)
        cout << i;
          

    cout <<endl;

    vector<int> v33 = right(v);
    for(auto i: v33)
        cout << i;

        
// 
}
