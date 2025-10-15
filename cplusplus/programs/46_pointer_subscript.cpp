#include <iostream>
int main()
{
    int a[5] = {2,4,6,8,10};
    int* p = a;

    std::cout << p[3] << " " << *(p+3) << " " << a[3] << std::endl; // 8 8 8

    return 0;
}