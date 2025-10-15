#include <iostream>
#include <cstddef>

std::size_t my_strlen(const char* s)
{
    const char* p = s;
    
    while (*p)
        ++p;

    return std::size_t(p - s);   // distance in elements
}

int main()
{
    const char* s="hello";
    std::cout << my_strlen(s) << std::endl;

    return 0;
}