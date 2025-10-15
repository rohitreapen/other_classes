#include <iostream>

class Point {
public:
    double x, y;
    Point()
    {
        x = 0.0;
        y = 0.0;
    }
};

int main() {
    Point p; // default constructor runs

    std::cout << p.x << "," << p.y << std::endl;

    return 0;
}
