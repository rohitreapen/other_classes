#include <fstream>
#include <iostream>
int main() {
    std::ofstream out("out1.txt", std::ios::out | std::ios::app);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out << "Appending a new line.\n";
}
