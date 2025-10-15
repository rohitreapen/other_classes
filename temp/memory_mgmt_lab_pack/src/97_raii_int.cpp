
#include <iostream>
class IntOwner {
    int* p;
public:
    explicit IntOwner(int v) : p(new int(v)) {}
    ~IntOwner(){ delete p; }
    int get() const { return *p; }
};
int main() {
    IntOwner x(10);
    std::cout << x.get() << "
";
}