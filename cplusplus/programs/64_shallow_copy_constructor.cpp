#include <iostream>
#include <cstring>

class Student {
public:
    int id;
    char* name;        // owning raw pointer for demo
    Student() : id(0), name(0) {}
};

int main() {
    Student s1;

    s1.id = 42;
    char buf[] = "foo";
    s1.name = buf;               

    Student s2 = s1;             // shallow copy: pointers equal
    s2.name[0] = 'b';            // mutates both!

    std::cout << s1.name << std::endl; // prints "boo"

    std::cout << "&s1.id : " << (&s1.id) <<
                 ", &s2.id : " << &s2.id <<
                 std::endl;

    std::cout << "s1.name : " << static_cast<const void*>(s1.name) <<
                 ", s2.name : " << static_cast<const void*>(s2.name) <<
                 std::endl;

    return 0;
}
