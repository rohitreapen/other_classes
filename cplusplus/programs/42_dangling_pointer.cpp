#include <iostream>

int* badFunc()
{
    int local = 4;
    return &local;
}  // returns address of a dead local!

int main()
{
    int* q = badFunc();        // q is dangling; do NOT dereference
    std::cout << "Received a dangling pointer (demo only)." << std::endl;

    return 0;
}