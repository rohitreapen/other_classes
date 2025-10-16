#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("nums25.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    long long sum = 0; long long n = 0; long long x;
    while (in >> x) { sum += x; ++n; }
    if (n) std::cout << "sum="<<sum<<" avg="<<(double)sum/n<<"\n";
}
