
#include <iostream>
#include <new>
int main(){
    int* p = new (std::nothrow) int[1000000000];
    if(!p) std::cout<<"allocation failed\n";
    else delete[] p;
}