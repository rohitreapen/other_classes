#include <iostream>
#include <string>

class Vehicle {
protected: 
    std::string license;
    int year;
public:
    Vehicle(const std::string& L,int Y):license(L),year(Y)
    {}
    std::string getDesc() const
    {
        return license + " (" + "Vehicle" + ")";
    }
};

class Car : public Vehicle {
    std::string style;
public:
    Car(const std::string& L,int Y,const std::string& S):Vehicle(L,Y),style(S)
    {}

    std::string getDesc() const
    {
        return style + ": " + license;
    } // overrides
};

int main()
{
    Car c("MIT-123", 2003, "hatch");
    
    std::cout << c.getDesc() << std::endl;

    return 0;
}
