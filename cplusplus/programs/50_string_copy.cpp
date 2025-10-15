#include <iostream>

void my_strcpy(char* dst, const char* src)
{
    *dst = *src;
    while (*src) 
    {
        *(++dst) = *(++src);
    }
}

int main()
{
    char buf[32];

    my_strcpy(buf, "Pointers!");

    std::cout << buf << std::endl;

    return 0;
}