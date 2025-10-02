#include <iostream>

int main() {
    int choice;
    std::cout << "1) Tea  2) Coffee  3) Juice  9) Exit";
    std::cout << std::endl << "Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Tea selected\n";
            break;
        case 2:
        case 3:
            std::cout << "Coffee or Juice!\n";
            break;
        case 9:
            std::cout << "Goodbye!\n";
            break;
        default:
            std::cout << "Unknown option\n";
    }

    return 0;
}
