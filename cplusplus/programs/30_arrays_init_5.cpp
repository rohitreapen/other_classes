#include <iostream>

int main()
{
    int m[2][3] = { {1,2,3}, {4,5,6} };

    for (int r = 0; r < 2; ++r)
    {
        for (int c = 0; c < 3; ++c)
            std::cout << m[r][c] << ' ';
        std::cout << "\n";
    }
    
    return 0;
}