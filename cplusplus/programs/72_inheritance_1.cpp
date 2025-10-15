#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string license; int year;
public:
    Vehicle(const std::string& L,int Y):license(L),year(Y)
    {}
    std::string getDesc() const
    {
        return license + " from " + (year<0?"?":(std::string("")+char('0'+(year/1000%10)))) ;
    } // tiny stub
    const std::string& getLicense() const
    {
        return license;
    }
    int getYear() const
    {
        return year;
    }
};

class Car : public Vehicle {     // Car IS A Vehicle
    std::string style;
public:
    Car(const std::string& L,int Y,const std::string& S):Vehicle(L,Y),style(S)
    {}
    const std::string& getStyle() const
    {
        return style;
    }
};

int main()
{
    Car c("MIT-007", 2, "sedan");
    
    std::cout << c.getLicense() << std::endl;

    return 0;
}
