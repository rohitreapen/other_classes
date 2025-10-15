
#include <iostream>
int main() {
    int* p = new int(7);
    delete p;
    // delete p; // UB if uncommented
    std::cout << "Freed once; second delete would be UB.
";
}