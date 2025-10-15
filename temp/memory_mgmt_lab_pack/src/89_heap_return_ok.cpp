
#include <iostream>
int* make_five() { int* p = new int(5); return p; }
int main() {
    int* p = make_five();
    std::cout << *p << "
";
    delete p;
}