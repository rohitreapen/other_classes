#include <iostream>

class Point {
private:
    double x, y;
public:
    Point(double nx, double ny) : x(nx), y(ny) 
    {}
};

int main() {
    Point p(2.0, 3.0);
    p.x = 5.0; // <- Uncomment to see "x is private" error
    std::cout << "ok\n";
}
