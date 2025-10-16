#include <fstream>
#include <iostream>
struct Rec { int id; double x; };
int main() {
    std::fstream f("db13.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (!f) { std::cerr << "open fail\n"; return 1; }
    Rec r[3] = {{1,1.1},{2,2.2},{3,3.3}};
    f.write(reinterpret_cast<const char*>(r), sizeof(r));
    Rec upd = {2, 9.9};
    f.seekp(sizeof(Rec) * 1, std::ios::beg);
    f.write(reinterpret_cast<const char*>(&upd), sizeof(upd));
}
