#include <iostream>

long sumToN(int n)
{
    long acc = 0;

    for (int i=1; i<=n; ++i)
        acc += i;

    return acc;
}

int main()
{ 
    int n;
    
    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::cout << sumToN(n) << std::endl;

    return 0;
}