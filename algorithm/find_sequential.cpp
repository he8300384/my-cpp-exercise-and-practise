//顺序查找
#include<iostream>

//顺序查找 查找数组 有此值返回 数组序号
template<typename T>
int seqentialSearch(T a[], int n, const T& x){ //c数组总是需要 显式传递数组长度
    
    for(int i = 0; i<n ; ++i)
    {
        if (a[i] == x) return i;         
    }

    std::cout << "not find\n";
    return -1;
}

//顺序查找 递归版本
template<typename T>
int rseqentialSearch(T a[], int n, const T& x){//c数组总是需要 显式传递数组长度
    if(n<1) return -1;
    if(a[n-1] == x) return n-1;
    return rseqentialSearch(a, n-1, x);
}

int main(){
    int a[6] = {2, 3, 4, 6, 8, 9};
    int result = 7;
    
    std::cout <<seqentialSearch(a, 6, result)<< std::endl;
    std::cout <<rseqentialSearch(a, 6, result)<< std::endl;
}