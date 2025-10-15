#include <iostream>

class A{
public:
    void f() const {
        std::cout<<"A" << std::endl;
    }
};

class B{
public:
    void f() const {
        std::cout<<"B" << std::endl;
    }
};

class C: public A, public B {
public:
    void callA() const {
        A::f();
    }
};

int main(){
    C c;
    c.callA(); 
    
    c.f(); // ERROR: ambiguous; need A::f or B::f 

    return 0;
}
