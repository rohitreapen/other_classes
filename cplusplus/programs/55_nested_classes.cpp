#include <iostream>

class Point {
public:
    double x, y;
};

class Vector {
public:
    Point start, end;
};

int main() {
    Vector v;
    v.start.x = 1.2;
    v.start.y = 0.4;
    v.end.x   = 2.0;
    v.end.y   = 1.6;

    std::cout << "(" << v.start.x << "," << v.start.y << ") -> ("
              << v.end.x   << "," << v.end.y   << ")\n";

    
    return 0;
}
