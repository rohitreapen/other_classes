#include <fstream>
#include <iostream>
int main() {
    std::fstream f("x27.txt", std::ios::in | std::ios::out | std::ios::trunc);
    if (!f) { std::cerr << "open fail\n"; return 1; }
    f << "ABCDEFGHIJ\n";
    f.seekp(3);
    f << "xyz";
}
