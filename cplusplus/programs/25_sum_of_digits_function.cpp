#include <iostream>

unsigned sumDigits(unsigned long x)
{
    if (x==0)
        return 1;

    unsigned sum=0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int main()
{
    unsigned long x;
    
    std::cout << "Enter x: ";
    std::cin >> x;
    
    std::cout << sumDigits(x) << std::endl;

    return 0;
}