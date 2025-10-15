#include <iostream>

int main()
{
    int a[8] = {0}; // every element = 0

    for (int i = 0; i < 8; ++i)
        std::cout << a[i] << ( i==7 ? '\n' : ' ' );

    return 0;
}