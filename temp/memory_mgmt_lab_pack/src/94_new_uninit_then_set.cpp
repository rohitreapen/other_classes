
#include <iostream>
int main() {
    int* p = new int;
    *p = 42;
    std::cout << *p << "
";
    delete p;
}