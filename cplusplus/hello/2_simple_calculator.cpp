#include <iostream>

int main() {
    int a, b; char op;
    std::cout << "enter calculation in the format" << std::endl;
    std::cout << "<num1> <operation> <num2>" << std::endl;
    std::cin >> a >> op >> b;

    if (op == '+') std::cout << a + b << std::endl;
    else if (op == '-') std::cout << a - b << std::endl;
    else if (op == '*') std::cout << a * b << std::endl;
    else if (op == '/') {
        if (b == 0) std::cout << "Division by zero!" << std::endl;
        else std::cout << a / b << std::endl;
    } else if (op == '%') {
        if (b == 0) std::cout << "Modulo by zero!" << std::endl;
        else std::cout << a % b << std::endl;
    } else std::cout << "Unknown operator" << std::endl;

    return 0;
}
