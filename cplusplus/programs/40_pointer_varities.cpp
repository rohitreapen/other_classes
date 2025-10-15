#include <iostream>
int main()
{
    int a = 10, b = 20;

    const int* p1 = &a;     // pointer to const int (data read-only via p1)
    // *p1 = 5;             // ERROR if uncommented
    p1 = &b;                // pointer itself can change

    int* const p2 = &a;     // const pointer to int (address fixed)
    *p2 = 11;               // data modifiable
    // p2 = &b;             // ERROR if uncommented

    const int* const p3 = &a;  // const pointer to const int
    
    std::cout << *p1 << " " << *p2 << " " << *p3 << std::endl;

    return 0;
}