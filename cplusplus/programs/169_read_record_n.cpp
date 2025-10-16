#include <fstream>
#include <iostream>
struct Rec { int id; double x; };
int main() {
    std::ifstream in("db13.bin", std::ios::binary);
    if (!in) { std::cerr << "open fail\n"; return 1; }
    Rec r;
    std::size_t n = 2;
    in.seekg(sizeof(Rec)*n, std::ios::beg);
    if (in.read(reinterpret_cast<char*>(&r), sizeof(r)))
        std::cout << "id="<<r.id<<" x="<<r.x<<"\n";
}
