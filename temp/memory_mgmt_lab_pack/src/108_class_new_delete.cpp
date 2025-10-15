
#include <iostream>
#include <new>
class Tracked{
public:
    static void* operator new(std::size_t sz){ std::cout<<"new "<<sz<<" bytes
"; return ::operator new(sz); }
    static void operator delete(void* p){ std::cout<<"delete
"; ::operator delete(p); }
};
int main(){ Tracked* t = new Tracked; delete t; }