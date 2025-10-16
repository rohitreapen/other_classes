#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::fstream f("dst.txt", std::ios::in | std::ios::out | std::ios::trunc);
    if (!f) { std::cerr << "open fail\n"; return 1; }
    f << "Line A\nLine B\n";
    f.flush();
    f.seekg(0);
    std::string s;
    while (std::getline(f, s)) std::cout << s << "\n";
}
