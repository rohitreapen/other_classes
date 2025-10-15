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
    Point p(2.0, 3.0);

    std::cout << p.x << "," << p.y << std::endl;

    return 0;
}
