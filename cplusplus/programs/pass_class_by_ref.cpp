#include <iostream>

class Point {
public:
    double x, y;
};

void offsetPoint(Point &p, double dx, double dy) { // reference
    p.x += dx;
    p.y += dy;
}

int main() {
    Point p = {3, 4};

    offsetPoint(p, 1, 2);
    std::cout << "(" << p.x << "," << p.y << ")" << std::endl; // now (4,6)

    return 0;
}
