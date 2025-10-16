#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
int main() {
    std::ifstream in("dst.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string line; long lines=0, words=0, chars=0;
    while (std::getline(in, line)) {
        ++lines; chars += line.size() + 1;
        std::string w; std::istringstream iss(line);
        while (iss >> w) ++words;
    }
    std::cout << "L="<<lines<<" W="<<words<<" C~="<<chars<<"\n";
}
