#include <fstream>
#include <iostream>
int main() {
    int a[5] = {0};
    std::ifstream in("data7.bin", std::ios::binary);
    if (!in) { std::cerr << "open fail\n"; return 1; }
    in.read(reinterpret_cast<char*>(a), sizeof(a));
    for (int i=0;i<5;++i) std::cout << a[i] << " ";
    std::cout << "\n";
}
