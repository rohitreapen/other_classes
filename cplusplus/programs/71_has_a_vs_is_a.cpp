#include <iostream>
#include <string>

class Engine {
    int hp; 
public:
    Engine(int h):hp(h)
    {}
    int getHP() const
    {
        return hp;
    }
};

class Car {                 // Car HAS an Engine (has-a)
    Engine engine;
    std::string model;
public:
    Car(std::string m,int hp):engine(hp),model(m)
    {}
    void spec() const
    {
        std::cout << model << " " << engine.getHP() << "HP" << std::endl;
    }
};

int main()
{
    Car c("Coupe", 180);
    c.spec();

    return 0;
}
