#include <iostream>

int main() {
    int n;
    do {
        std::cout << "Enter a number between 1 and 10: ";
        std::cin >> n;
    } while (n < 1 || n > 10);

    std::cout << "You chose " << n << "\n";

    return 0;
}
