#include <iostream>

int main()
{
    long arr[4] = {6,0,9,6};
    long* ptr = arr;
    std::cout << "*ptr=" << *ptr << std::endl;   // 6

    ++ptr;                                  // moves by sizeof(long)
    std::cout << "*ptr=" << *ptr << std::endl;   // 0

    std::cout << arr[2] << " " << *(arr+2) << std::endl;
    std::cout << arr[2] << " " << *(ptr+1) << std::endl;

    return 0;
}