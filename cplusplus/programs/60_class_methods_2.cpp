#include <iostream>

class Point {
public:
    double x, y;
    void offset(double dx, double dy);
    void print();
};

class Vector {
public:
    Point start, end;
    void offset(double dx, double dy);
    void print();
};

void Point::offset(double dx, double dy)
{
    x += dx;
    y += dy;

}
void Point::print()
{
    std::cout << "(" << x << "," << y << ")";

}
void Vector::offset(double dx, double dy)
{
    start.offset(dx,dy);
    end.offset(dx,dy);
}
void Vector::print()
{
    start.print();
    std::cout << " -> ";
    end.print();
}

int main() {
    Vector v;

    v.start.x = 0;
    v.start.y = 0;
    v.end.x   = 1;
    v.end.y   = 1;

    v.offset(2,3);
    
    v.print();
    std::cout << std::endl;

    return 0;
}
