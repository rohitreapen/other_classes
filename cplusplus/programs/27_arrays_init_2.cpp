#include <iostream>

int main()
{
    int a[5] = {1, 2};  // -> {1,2,0,0,0}

    for (int i = 0; i < 5; ++i)
        std::cout << a[i] << ( i==4 ? '\n' : ' ' );

    return 0;
}