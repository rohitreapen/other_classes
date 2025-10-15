#include <iostream>

class InsuredItem {
public:
    virtual ~InsuredItem()
    {}
    virtual void policy() const {
        std::cout<<"Policy" << std::endl;
    }
};

class Vehicle {
public:
    virtual ~Vehicle()
    {}
    virtual void info()   const {
        std::cout<<"Vehicle" << std::endl;
    }
};

class Car : public Vehicle, public InsuredItem {
public:
    void info() const {
        std::cout<<"Car" << std::endl;
    }
};

int main(){
    Car c;
    
    c.info();
    c.policy();
    Vehicle &v = c;
    v.info();

    return 0;
}
