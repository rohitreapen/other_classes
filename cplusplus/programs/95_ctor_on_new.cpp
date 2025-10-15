
#include <iostream>
class X { public: X(){ std::cout << "X()\n"; } };
int main() {
    X* p = new X; delete p;
    X* a = new X[3]; delete[] a;
}