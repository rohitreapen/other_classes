#include <iostream>

class Base {
public:
    void f()
    {}
};

class Pub : public Base 
{};       // f() stays public

class Pro : protected Base
{};    // f() becomes at most protected

int main(){ 
    Pub a; 
    a.f(); // Allowed

    Pro b; 
    b.f(); // ERROR: now protected */ 

    return 0;
}
