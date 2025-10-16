#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("dst.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string s;
    while (true) {
        if (!(in >> s)) break;
        std::cout << s << "\n";
    }
    std::cerr << "eof=" << in.eof() << " fail=" << in.fail() << " bad=" << in.bad() << "\n";
}
