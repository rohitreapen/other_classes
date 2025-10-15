#include <iostream>

class Base {
public:
    // try toggling virtual on/off here
    virtual ~Base()
    {
        std::cout << "~Base\n";
    }
    virtual void f()
    {}
};

class Derived : public Base {
    int* big_;
public:
    Derived() : big_(new int[1000])
    {}
    ~Derived()
    {
        std::cout << "~Derived\n"; delete[] big_;
    }
};

int main() {
    Base* p = new Derived;
    delete p;  // needs virtual ~Base() to call ~Derived() first
}
