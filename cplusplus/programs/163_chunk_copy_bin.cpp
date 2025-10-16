#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("log9.bin", std::ios::binary);
    std::ofstream out("copy22.bin", std::ios::binary);
    if (!in || !out) { std::cerr << "open fail\n"; return 1; }
    const std::size_t BUFSZ = 4096;
    char buf[BUFSZ];
    while (in) {
        in.read(buf, BUFSZ);
        std::streamsize n = in.gcount();
        if (n > 0) out.write(buf, n);
    }
}
