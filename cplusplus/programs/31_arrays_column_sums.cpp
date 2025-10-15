#include <iostream>

int main()
{
    const int R=3, C=3;
    int m[R][C] = { {2,1,0}, {3,5,7}, {4,6,8} };

    for (int c = 0; c < C; ++c)
    {
        int sum = 0;
        for (int r = 0; r < R; ++r)
            sum += m[r][c];
        std::cout << "col " << c << " sum = " << sum << std::endl;
    }

    return 0;
}