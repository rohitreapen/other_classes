#include <iostream>

int main()
{
    char s[] = "HELLO";              // size = 6 including '\0'

    for (int i = 0; s[i] != '\0'; ++i)
        std::cout << s[i] << ' ';
    std::cout << "\n";

    s[1] = 'a';                      // overwrite a character
    std::cout << s << "\n";          // prints "HaLLO"

    return 0;
}