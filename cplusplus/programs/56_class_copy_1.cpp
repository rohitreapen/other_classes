#include <iostream>

class Point {
public:
    double x, y;
};

int main() {
    Point a;

    a.x = 3;
    a.y = 4;
    Point b = a;        // memberwise copy
    b.x = 7;            // independent copy

    std::cout << "a:(" << a.x << "," << a.y << ") b:("
              << b.x << "," << b.y << ")" << std::endl;
    std::cout << "&a: " << &a << ", " << "&b: "
              << &b << std::endl;
    
    return 0;
}
