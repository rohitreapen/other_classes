#include <iostream>

class Point {
public:
    double x, y;   // public data (like the old struct)
};

int main() 
{
    Point p; 
    p.x = 1.5; 
    p.y = -2.0;
    std::cout << "(" << p.x << ", " << p.y << ")\n";

    return 0;
}
