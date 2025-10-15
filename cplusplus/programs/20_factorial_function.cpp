#include <iostream>

int factorial(int n) 
{
    int f = 1;
    for (int i = 2; i <= n; ++i)
        f *= i;

    return f;
}

int main() 
{
    int n;

    std::cout << "Enter n: "; 
    std::cin >> n;
    std::cout << n << "! = " << factorial(n) << std::endl;

    return 0;
}