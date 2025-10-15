#include <iostream>
#include <string>

class Vehicle {
public: 
    std::string getDesc() const
    {
        return "Vehicle";
    } // NOT virtual
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
    Vehicle* vp = &c;
    
    std::cout << vp->getDesc() << std::endl; // "Vehicle"

    return 0;

}
