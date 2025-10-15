#include <iostream>

class Point {
public:
    double x, y;
    Point() : x(0), y(0)
    {}
    void print()
    {
        std::cout << "(" << x << "," << y << ") ";
    }
};

int main() {
    Point pts[3];

    for (int i = 0; i < 3; ++i)
    {
        pts[i].x = i;
        pts[i].y = -i;
    }

    for (int i = 0; i < 3; ++i)
        pts[i].print();

    std::cout << std::endl;

    return 0;
}
