#include <iostream>

int main()
{
    char course1[] = { '6','.', '0','9','6','\0' }; // modifiable array
    const char* course2 = "6.096";                  // string literal (read-only)

    course1[1] = 'X';                               // OK
    // course2[1] = 'X';                            // RUNTIME ERROR if attempted
    std::cout << course1 << " | " << course2 << std::endl;

    return 0;
}