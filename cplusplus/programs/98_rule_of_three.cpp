
#include <iostream>
#include <cstring>
class Name {
    char* s;
public:
    Name(): s(0) {}
    explicit Name(const char* t){ s=new char[std::strlen(t)+1]; std::strcpy(s,t); }
    Name(const Name& o){ if(o.s){ s=new char[std::strlen(o.s)+1]; std::strcpy(s,o.s);} else s=0; }
    Name& operator=(const Name& o){
        if(this!=&o){
            char* ns=0;
            if(o.s){ ns=new char[std::strlen(o.s)+1]; std::strcpy(ns,o.s); }
            delete[] s; s=ns;
        }
        return *this;
    }
    ~Name(){ delete[] s; }
    const char* c_str() const { return s? s : ""; }
};
int main() {
    Name a("Alice"), b=a;
    std::cout << b.c_str() << "\n";
}