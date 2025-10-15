
#include <iostream>
class Holder{ int* p; public: Holder():p(new int(5)){} ~Holder(){ delete p; } };
void might_throw(){ throw 1; }
int main(){
    try{ Holder h; might_throw(); }
    catch(...){ std::cout<<"no leak
"; }
}