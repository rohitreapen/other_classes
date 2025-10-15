#include <iostream>
int main()
{
    int a[4] = {10,20,30,40};
    int* p = a;                      // points to first element
    std::cout << a[0] << " " << *p << std::endl;
    std::cout << a[2] << " " << *(a+2) << std::endl;
    std::cout << a[2] << " " << *(p+2) << std::endl;

    return 0;
}