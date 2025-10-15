
#include <iostream>
class Bad { public: char* s; };
int main() {
    char buf[] = "hi";
    Bad a; a.s = buf;
    Bad b = a;
    b.s[0] = 'b';
    std::cout << a.s << "
";
}