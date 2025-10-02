#include <iostream>

int main() {
    int n;

    std::cout << "Enter any integer: ";
    std::cin >> n;

    if (n)
      std::cout << "This counts as TRUE (non-zero)." << std::endl;
    else
      std::cout << "This counts as FALSE (zero)." << std::endl;

    return 0;
}
