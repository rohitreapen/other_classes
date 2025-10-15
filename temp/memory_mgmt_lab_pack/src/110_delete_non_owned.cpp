
#include <iostream>
class Bad{ public: const char* s; /* ~Bad(){ delete[] s; } */ };
int main(){ Bad b; b.s = "literal"; std::cout << b.s << "
"; }