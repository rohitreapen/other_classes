#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("out1.txt");
    if (!in) { std::cerr << "open src fail\n"; return 1; }
    std::ofstream out("dst.txt");
    if (!out) { std::cerr << "open dst fail\n"; return 1; }
    std::string line;
    while (std::getline(in, line)) out << line << "\n";
}
