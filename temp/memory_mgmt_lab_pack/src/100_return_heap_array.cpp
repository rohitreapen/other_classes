
#include <iostream>
int* make_arr(int n){
    int* a = new int[n];
    for(int i=0;i<n;++i) a[i]=i;
    return a;
}
int main(){
    int* a = make_arr(5);
    for(int i=0;i<5;++i) std::cout<<a[i]<<" ";
    std::cout<<"
";
    delete[] a;
}