
#include <iostream>
int main() {
    int n = 5;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) { a[i] = i * i; }
    for (int i = 0; i < n; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
    delete[] a;
}