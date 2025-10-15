#include <iostream>

class Vehicle {
public:
    virtual ~Vehicle()
    {}
    virtual void id() const {
        std::cout<<"V\n";
    }
};

class Car : public Vehicle {
public:
    void id() const {
        std::cout<<"C\n";
    }
};

void show(Vehicle v){
    v.id();      // pass by value: slices Car part off!
}

void showRef(Vehicle& v){
    v.id();      // pass by reference: uses Car class members
}

int main(){
    Car c; 
    
    show(c); // prints "V"

    showRef(c); // prints "C"

    return 0;
}       
