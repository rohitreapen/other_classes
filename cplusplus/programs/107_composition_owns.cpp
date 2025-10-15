
#include <iostream>
#include <cstring>
class Person{
    char* name;
public:
    Person(): name(0) {}
    explicit Person(const char* n){ name=new char[std::strlen(n)+1]; std::strcpy(name,n); }
    ~Person(){ delete[] name; }
    const char* get() const { return name? name : ""; }
};
class Team{
    Person lead;
public:
    explicit Team(const char* n): lead(n) {}
    void print() const { std::cout << lead.get() << "\n"; }
};
int main(){ Team t("Ada"); t.print(); }