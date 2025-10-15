#include <iostream>

class Shape {
public:
    virtual ~Shape()
    {}
    virtual double area() const = 0;
};

class Rect : public Shape {
    double w, h; 
public:
    Rect(double W,double H) : w(W), h(H)
    {}
    double area() const {
        return w * h;
    }
};

class Tri  : public Shape {
    double b, h;
public:
    Tri(double B,double H) : b(B), h(H)
    {}
    double area() const {
        return 0.5 * b * h;
    }
};

int main(){
    Rect r(3, 4);
    Tri t(3, 4);
    Shape* s[2] = { &r, &t};
    
    std::cout << s[0]->area() << " "<< s[1]->area() << std::endl;

    return 0;
}
