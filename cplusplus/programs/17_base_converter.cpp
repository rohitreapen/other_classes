#include <iostream>
#include <string>

int main()
{
    unsigned long n;
    int base;
    std::cout << "Enter a non-negative integer and base (2, 8, or 16): ";
    std::cin >> n >> base;
    if (!(base == 2 || base == 8 || base == 16))
    {
        std::cout << "Base must be 2, 8, or 16.\n";
        return 0;
    }

    if (n == 0)
    {
        std::cout << "0\n"; return 0;
    }

    std::string out;
    while (n > 0)
    {
        int r = int(n % base);
        char ch = r < 10 ? char('0' + r) : char('A' + (r - 10));
        out += ch; // build the result in reverse
        n /= base;
    }

    // print the reverse resuult which is itself in reverse
    for (int i = int(out.size()) - 1; i >= 0; --i)
        std::cout << out[i];

    std::cout << "\n";

    return 0;
}
