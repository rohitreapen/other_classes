#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("162_bin_size.exe", std::ios::binary);
    if (!in) { std::cerr << "open fail\n"; return 1; }
    in.seekg(0, std::ios::end);
    std::streampos sz = in.tellg();
    std::cout << "bytes=" << sz << "\n";
}
