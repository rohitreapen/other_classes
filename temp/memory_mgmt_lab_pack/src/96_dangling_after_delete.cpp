
#include <iostream>
int main() {
    int* p = new int(9);
    delete p;
    // std::cout << *p << "
"; // would be dangling
    p = 0;
}