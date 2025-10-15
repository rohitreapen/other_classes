#include <iostream>

int main()
{
    int n;
    
    std::cout << "Enter a number = number of rows/columns (square): ";
    std::cin >> n;
    if(n <= 0)
        return 0;

    int a[25][25];
    if(n > 25) 
        n = 25;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            std::cin >> a[i][j];

    int d1 = 0,d2 = 0;
    
    for(int i = 0; i < n; ++i)
    {
        d1 += a[i][i];
        d2 += a[i][n-1-i];
    }
    std::cout << "main diag=" << d1 << " other diag=" << d2 << std::endl;

    return 0;
}