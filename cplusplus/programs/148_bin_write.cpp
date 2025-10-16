#include <fstream>
#include <iostream>
int main() {
    int a[5] = {1,2,3,4,5};
    std::ofstream out("data7.bin", std::ios::binary);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out.write(reinterpret_cast<const char*>(a), sizeof(a));
}
