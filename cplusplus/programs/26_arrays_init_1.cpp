#include <iostream>

int main()
{
    int a[] = {10, 20, 30, 40};
             // size deduced = 4
    for (int i = 0; i < 4; ++i)
        std::cout << a[i] << ( i==3 ? '\n' :' ');

    return 0;
}