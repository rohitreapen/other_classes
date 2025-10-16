#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("out1.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string word;
    while (in >> word) std::cout << word << "\n";
}
