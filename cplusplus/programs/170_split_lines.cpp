#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("nums25.txt");
    std::ofstream odd("odd29.txt"), even("even29.txt");
    if (!in || !odd || !even) { std::cerr << "open fail\n"; return 1; }
    std::string line; long i=0;
    while (std::getline(in, line)) {
        (++i % 2 ? odd : even) << line << "\n";
    }
}
