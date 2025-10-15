
#include <iostream>
void alloc(int*& p, int n){ p = new int[n]; }
void init (int* p, int n){ for(int i=0;i<n;++i) p[i]=i; }
void free_(int*& p){ delete[] p; p=0; }
int main(){
    int* a = 0;
    alloc(a,5);
    init(a,5);
    for(int i=0;i<5;++i) std::cout<<a[i]<<" ";
    std::cout<<"\n";
    free_(a);
}