#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("out1.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string line;
    while (std::getline(in, line)) std::cout << line << "\n";
}
