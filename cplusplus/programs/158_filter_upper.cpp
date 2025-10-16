#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
int main() {
    std::ifstream in("out1.txt");
    std::ofstream out("dst17.txt");
    if (!in || !out) { std::cerr << "open fail\n"; return 1; }
    char ch;
    while (in.get(ch)) out << char(std::toupper((unsigned char)ch));
}
