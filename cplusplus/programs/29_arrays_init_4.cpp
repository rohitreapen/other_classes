#include <iostream>

int main()
{
    const int N = 5;
    int a[N];

    std::cout << "Enter 5 integers: ";
    for (int i = 0; i < N; ++i)
        std::cin >> a[i];

    for (int i = 0; i < N; ++i)
        std::cout << "a["<<i<<"]="<<a[i] << std::endl;

    return 0;
}