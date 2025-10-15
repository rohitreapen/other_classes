#include <iostream>
int main()
{
    int a[5] = {1,2,3,4,5};

    for (int* p = a + 5; p-- != a; )
        std::cout << *p << " ";

    std::cout << std::endl;

    return 0;
}