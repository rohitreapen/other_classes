#include <iostream>

struct S
{
    int a;
};     // public by default

class C
{
    int a;
};      // private by default

int main() {
    S s; 
    
    s.a = 5;         // OK

    C c; 
    c.a = 5;      // Uncomment -> error (a is private)

    std::cout << s.a << std::endl;

    return 0;
}
