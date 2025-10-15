#include <iostream>
#include <cstring>

class Student {
public:
    int id;
    char* name;

    Student() : id(0), name(0) {}

    Student(const Student& o) : id(o.id)
    {            // deep copy
        if (o.name)
        {
            name = new char[std::strlen(o.name)+1];
            std::strcpy(name, o.name);
        }
        else
            name = 0;
    }

    Student(int id, const char* str)
    {            // deep copy
        if (str)
        {
            name = new char[std::strlen(str)+1];
            std::strcpy(name, str);
        }
        else
            name = 0;
    }

    ~Student()
    {
        if (name)
            delete[] name; // tidy up
    }                     
};

int main() {    
    char buf[] = "foo";
    
    Student s1(7, buf);

    Student s2 = s1;             // deep copy; pointers differ

    if (s2.name)
        s2.name[0] = 'b';

    std::cout << "s1.name: " << s1.name << std::endl; // still "foo"
    std::cout << "s2.name: " << s2.name << std::endl;
}
