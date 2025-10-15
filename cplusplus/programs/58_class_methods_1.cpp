#include <iostream>
class Point {
public:
    double x, y;

    void offset(double dx, double dy) { 
        x += dx;
        y += dy;
    }

    void print()
    {
        std::cout << "(" << x << "," << y << ")";
    }
};

int main() {
    Point p;
    
    p.x = 1.2;
    p.y = 0.4;

    p.offset(1.0, 1.5);

    p.print();
    
    std::cout << std::endl;

    return 0;
}
