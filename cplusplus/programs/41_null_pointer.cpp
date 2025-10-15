#include <iostream>
int main()
{
    int* p = 0;                         // null pointer
    if (p == 0)
        std::cout << "p is null" << std::endl;

    int x = 7;
    p = &x;

    if (p)
        std::cout << "*p=" << *p << std::endl;

    return 0;
}