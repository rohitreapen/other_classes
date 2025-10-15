#include <iostream>
class Point {
public:
    double x, y;
};

void offsetPoint(Point p, double dx, double dy) { // copy
    p.x += dx;
    p.y += dy;
}

int main() {
    Point p = {3, 4};   // aggregate init is OK (no ctors, public data)

    offsetPoint(p, 1, 2);
    std::cout << "(" << p.x << "," << p.y << ")" << std::endl; // still (3,4)

    return 0;
}
