#include <iostream>

const char* my_strchr(const char* s, int ch)
{
    for (; *s; ++s)
        if (*s == ch)
            return s;

    return 0;
}

int main()
{
    const char* s="hello";

    const char* p=my_strchr(s,'l');

    std::cout << (p ? p : "(not found)") << std::endl;

    return 0;
}