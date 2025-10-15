#include <iostream>

class Point {
public:
    double x, y;
    Point(double nx, double ny)
    {
        x = nx;
        y = ny;
    }
};

int main() {
    Point q(1.0, 2.0);

    Point r = q; // copy constructor invoked

    std::cout << r.x << "," << r.y << std::endl;
    std::cout << "&q = " << &q << ": &r = " << &r << std::endl;

    return 0;
}
