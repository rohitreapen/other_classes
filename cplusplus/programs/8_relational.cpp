#include <iostream>

int main() {
    int x, y;
    std::cout << "Enter x y: ";
    std::cin >> x >> y;

    std::cout << "(x > y)  = " << (x > y)  << std::endl;
    std::cout << "(x < y)  = " << (x < y)  << std::endl;
    std::cout << "(x == y) = " << (x == y) << std::endl;
    std::cout << "(x != y) = " << (x != y) << std::endl;
    std::cout << "(x > 0 && y > 0) = " << (x > 0 && y > 0) << std::endl;
    std::cout << "!(x == 0)        = " << !(x == 0) << std::endl;

    return 0;
}
