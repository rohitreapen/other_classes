#include <iostream>

bool isPrime(int x)
{
    if (x < 2) 
        return false;
    if (x % 2 == 0) 
        return x == 2;
    for (int d = 3; d*d <= x; d += 2) 
        if (x %d ==0) 
            return false;

    return true;
}

int main()
{ 
    int n;

    std::cout << "N: ";
    std::cin >> n;
    
    std::cout<<( isPrime(n) ? "prime\n" : "not prime\n" );

    return 0;
}