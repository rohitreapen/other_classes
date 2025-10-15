
#include <iostream>
#include <cstring>
class MiniStr{
    char* s;
public:
    MiniStr(): s(0) {}
    explicit MiniStr(const char* t){ s=new char[std::strlen(t)+1]; std::strcpy(s,t); }
    MiniStr(const MiniStr& o){ if(o.s){ s=new char[std::strlen(o.s)+1]; std::strcpy(s,o.s);} else s=0; }
    MiniStr& operator=(const MiniStr& o){
        if(this!=&o){
            char* ns=0;
            if(o.s){ ns=new char[std::strlen(o.s)+1]; std::strcpy(ns,o.s); }
            delete[] s; s=ns;
        }
        return *this;
    }
    ~MiniStr(){ delete[] s; }
    const char* c_str() const { return s? s : ""; }
};
int main(){ MiniStr a("hi"), b=a; std::cout<<b.c_str()<<"\n"; }