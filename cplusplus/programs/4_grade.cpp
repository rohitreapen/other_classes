#include <iostream>

int main() {
    int m; 
    std::cout << "Enter mark (0-100): ";
    std::cin >> m;

    if (m < 0 || m > 100) std::cout << "Invalid" << std::endl;
    else if (m >= 90) std::cout << "Grade: A" << std::endl;
    else if (m >= 80) std::cout << "Grade: B" << std::endl;
    else if (m >= 70) std::cout << "Grade: C" << std::endl;
    else if (m >= 60) std::cout << "Grade: D" << std::endl;
    else std::cout << "Grade: F" << std::endl;

    return 0;
}
