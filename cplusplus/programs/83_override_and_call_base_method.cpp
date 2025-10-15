#include <iostream>

class A {
public:
    virtual ~A()
    {}
    virtual void f() const
    { 
        std::cout<<"A" << std::endl;
    }
};

class B : public A {
public:
    void f() const {
         std::cout<<"B:"; A::f();
    }
};

int main(){
    B b;
    A* p = &b;
    p->f();

    return 0;

}  // prints "B:A"
