#include <iostream>
int main() {
    int x;
    std::cout << "Enter a number (1..10): ";
    std::cin >> x;

    if (x >= 1 && x <= 10)
    {
        std::cout << "In range" << std::endl;
    } else {
        std::cout << "Out of range" << std::endl;
    }

    return 0;
}
