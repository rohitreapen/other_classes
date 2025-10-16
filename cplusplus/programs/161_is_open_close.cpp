#include <fstream>
#include <iostream>
int main() {
    std::ofstream out;
    out.open("out20.txt");
    if (!out.is_open()) { std::cerr << "open fail\n"; return 1; }
    out << "OK\n";
    out.close();
    if (out.is_open()) std::cerr << "still open?\n";
}
