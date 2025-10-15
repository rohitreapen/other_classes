#include <iostream>
#include <string>

class Vehicle { // Abstract class
public:
    int m;
    virtual std::string getDesc() const = 0; // pure virtual
};
class Car : public Vehicle {
public:
    Car (int m_)
    {
        m = m_;
    } 
    std::string getDesc() const
    {
        return "Car";
    }
    int getM () const
    {
        return m;
    }
};
int main(){
    /* Vehicle v; // ERROR: abstract */ 
    
    Car c(3);
    std::cout<<c.getDesc()<< " " << c.getM() << std::endl;

    return 0;
}
