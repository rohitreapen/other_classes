#include <iostream>

int main()
{
    const char days[7][4] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    for (int i = 0; i < 7; ++i)
        std::cout << i << ": " << days[i] << "\n";

    std::cout << days[0][1] << "\n";
    // Access: days[0][1] is 'u', days[2] is "Tue"

    return 0;
}