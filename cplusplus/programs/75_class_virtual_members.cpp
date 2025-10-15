#include <iostream>
#include <string>

class Vehicle {
public: 
    virtual ~Vehicle()
    {}                  // virtual destructor
    virtual std::string getDesc() const
    {
        return "Vehicle";
    }
};

class Car : public Vehicle {
public:
    std::string getDesc() const
    {
        return "Car";
    }
};

int main(){
    Car c;
    Vehicle* vp = &c;           // base ptr to derived obj

    std::cout << vp->getDesc() << std::endl; // prints "Car" because virtual

    return 0;
}
