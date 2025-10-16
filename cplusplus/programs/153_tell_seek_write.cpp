#include <fstream>
#include <iostream>
int main() {
    std::ofstream out("out12.txt", std::ios::out | std::ios::trunc);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out << "XXXXXXXXXX\n";
    out.seekp(0);
    out << "HELLO";
}
