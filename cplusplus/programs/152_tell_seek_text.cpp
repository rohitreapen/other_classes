#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("dst.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    in.seekg(3);
    std::streampos p0 = in.tellg();
    std::string first;
    std::getline(in, first);
    std::cout << "First line: " << first << "\n";
    in.seekg(p0);
    std::string again;
    std::getline(in, again);
    std::cout << "Again: " << again << "\n";
}
