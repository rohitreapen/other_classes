#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream a("out1.txt"), b("dst.txt");
    std::ofstream out("m18.txt");
    if (!a || !b || !out) { std::cerr << "open fail\n"; return 1; }
    std::string s, t;
    bool ha = bool(std::getline(a, s)), hb = bool(std::getline(b, t));
    while (ha || hb) {
        if (!hb || (ha && s <= t)) { out << s << "\n"; ha = bool(std::getline(a, s)); }
        else                        { out << t << "\n"; hb = bool(std::getline(b, t)); }
    }
}
