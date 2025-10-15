#include <iostream>
void squareByPtr(int* numPtr)
{
    *numPtr = (*numPtr) * (*numPtr);
}

int main()
{
    int a=5;
    squareByPtr(&a);
    std::cout << a << std::endl;

    return 0;
}