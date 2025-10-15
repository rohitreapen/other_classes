
#include <iostream>
int* bad() { int x = 5; return &x; }
int main() {
    int* p = bad();
    std::cout << "Dangling demo; do not dereference p!
";
}