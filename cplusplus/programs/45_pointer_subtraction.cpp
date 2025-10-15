#include <iostream>
int main()
{
    long arr[4] = {6,0,9,6};

    long* p = arr;
    long* q = arr + 3;

    std::cout << "q - p = " << (q - p) << std::endl;  // 3 elements apart

    return 0;
}