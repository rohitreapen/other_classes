#include <iostream>

class Counter {
    int value;                 // hidden (data hiding)
public:
    Counter() : value(0)
    {}
    void inc()
    {
        ++value;
    }    // public interface
    int get() const
    {
        return value;
    }
};

int main()
{
    Counter c;

    c.inc();
    std::cout << c.get() << std::endl;

    return 0;
}
