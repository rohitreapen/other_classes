
#include <iostream>
int main() {
    int a = 5;
    int* p = new int(5);
    std::cout << a << " " << *p << "\n";
    delete p;
}