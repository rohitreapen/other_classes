#include <iostream>
int main()
{
    int x = 42;
    int* p = &x;                 // &x = address of x

    std::cout << "x=" << x << std::endl;
    std::cout << "p (addr)=" << p << std::endl;
    std::cout << "*p (value)=" << *p << std::endl;  // dereference
    *p = 99;                                   // write through pointer
    std::cout << "x after *p=99 -> " << x << std::endl;

    return 0;
}