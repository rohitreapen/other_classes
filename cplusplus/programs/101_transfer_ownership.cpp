
#include <iostream>
int* make_val(){ return new int(7); }
void take_ownership(int* p){ std::cout<<*p<<"\n"; delete p; }
int main(){
    int* p = make_val();
    take_ownership(p);
    p = 0;
}