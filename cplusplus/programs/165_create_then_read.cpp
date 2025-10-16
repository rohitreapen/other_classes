#include <fstream>
#include <iostream>
#include <string>
int main() {
    { std::ofstream out("maybe24.txt", std::ios::app); }
    std::ifstream in("maybe24.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string s; while (std::getline(in, s)) std::cout << s << "\n";
}
