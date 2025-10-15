#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string license;
    int year;
public: 
    Vehicle(const std::string& L,int Y):license(L),year(Y)
    {}
    virtual std::string getDesc() const
    {
        return license;
    }
};

class Car : public Vehicle {
    std::string style;
public:
    Car(const std::string& L,int Y,const std::string& S):Vehicle(L,Y),style(S)
    {}
    std::string getDesc() const
    {
        return style + ": " + Vehicle::getDesc(); // add to base
    }
};

int main(){
    Car c("MIT-999", 2010, "sedan");
    
    std::cout<<c.getDesc()<< std::endl;

    return 0;
}
