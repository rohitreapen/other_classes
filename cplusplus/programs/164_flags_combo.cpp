#include <fstream>
#include <iostream>
int main() {
    std::fstream f("combo23.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!f) { std::cerr << "open fail\n"; return 1; }
    f << "Appended line\n";
}
