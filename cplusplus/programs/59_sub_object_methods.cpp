#include <iostream>
class Point {
public:
    double x, y;
    void offset(double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    void print()
    {
        std::cout << "(" << x << "," << y << ")";
    }
};

class Vector {
public:
    Point start, end;
    void offset(double dx, double dy)
    {
        start.offset(dx,dy);
        end.offset(dx,dy);
    }
    void print()
    {
        start.print();
        std::cout << " -> ";
        end.print();
    }
};

int main() {
    Vector v;

    v.start.x = 1.2;
    v.start.y = 0.4;
    v.end.x   = 2.0;
    v.end.y   = 1.6;   // (no brace-assignments in C++98)

    v.offset(1.0, 1.5);
    v.print();
    std::cout << std::endl;

    return 0;
}
