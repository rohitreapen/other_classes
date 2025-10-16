#include <fstream>
#include <iostream>
int main() {
    std::ofstream out("out1.txt", std::ios::out | std::ios::trunc);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out << "Hello file!\n";
}
