#include <iostream>

int main() {
    int x, y;

    std::cout << "x y: ";
    std::cin >> x >> y;

    if (x > y)
    {
        std::cout << "x > y\n";
        if (x == 6)
          std::cout << "Also, x == 6\n";
        else
          std::cout << "Also, x != 6\n";
    }
    else
        std::cout << "x <= y\n";

    return 0;
}
