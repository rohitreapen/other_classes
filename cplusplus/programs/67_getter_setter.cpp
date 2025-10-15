#include <iostream>

class Point {
private:
    double x, y;
public:
    Point(double nx, double ny) : x(nx), y(ny) 
    {}
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
};

int main() {
    Point p(2.0, 3.0);

    std::cout << p.getX() << "," << p.getY() << std::endl;

    return 0;
}
