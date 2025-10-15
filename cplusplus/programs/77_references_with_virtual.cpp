#include <iostream>
#include <string>

class Vehicle {
public:
    virtual ~Vehicle()
    {}
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

void print(const Vehicle& v)
{
    std::cout << v.getDesc() << std::endl; // virtual works
} 

int main(){
    Car c;
    
    print(c);

    Vehicle &p = c;

    std::cout << "Vehicle reference in main: " << p.getDesc() << std::endl;
    
    return 0;
}
