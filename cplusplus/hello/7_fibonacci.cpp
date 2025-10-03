#include <iostream>

int main() {
    int n;
    
    std::cout << "Enter number of terms: ";
    std::cin >> n;
    if (n > 0)
    {
        int a = 0, b = 1;
        for (int i = 1; i <= n; ++i)
        {
            std::cout << a << (i == n ? '\n' : ' ');
            int next = a + b;
            a = b; b = next;
        }
    }
    else
    {
        std::cout << "Number of terms not greater than zero" <<
        std::endl;
    }
    

    return 0;
}
