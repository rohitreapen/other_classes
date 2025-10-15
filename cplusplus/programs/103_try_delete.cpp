
#include <iostream>
void might_throw(bool t){ if(t) throw 42; }
int main(){
    int* p = new int(5);
    try{ might_throw(true); }
    catch(...){ delete p; p=0; }
}