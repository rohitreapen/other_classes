#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string license;
    int year; // visible to derived, not to users
public:
    Vehicle(const std::string& L,int Y):license(L),year(Y)
    {}
};

class Car : public Vehicle {
public:
    Car(const std::string& L,int Y):Vehicle(L,Y)
    {}
    void reregister(const std::string& L)
    {
        license = L;
    } // allowed: protected
};

int main()
{
    Car c("ABC", 1999);
    
    c.reregister("XYZ"); 
    
    std::cout<<c.license; // ERROR

    return 0;
}
