#include <iostream>

class Point {
public:
    double x, y;
    Point()
    {
        x = 0.0;
        y = 0.0;
    }
    Point(double nx, double ny)
    {
        x = nx;
        y = ny;
    }
};

int main() {
    Point a;         // default

    Point b(5.0, 6.0); // 2-arg

    std::cout << a.x << "," << a.y << " | " << b.x << "," << b.y << std::endl;

    return 0;
}
