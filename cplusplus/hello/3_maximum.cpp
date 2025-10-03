#include <iostream>

int main() {
    int a, b, c;
    std::cout << "Enter three integers: ";
    std::cin >> a >> b >> c;

    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    std::cout << "Maximum of the three = " << m << std::endl;

    return 0;
}
