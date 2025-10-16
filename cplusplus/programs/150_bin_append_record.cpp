#include <fstream>
#include <iostream>
struct Rec { int id; double x; };
int main() {
    Rec r = {42, 3.14};
    std::ofstream out("log9.bin", std::ios::binary | std::ios::app);
    if (!out) { std::cerr << "open fail\n"; return 1; }
    out.write(reinterpret_cast<const char*>(&r), sizeof(r));
}
