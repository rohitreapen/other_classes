#include <fstream>
#include <iostream>
#include <string>
int main() {
    std::ifstream in("username.csv");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string field;
    while (std::getline(in, field, ';')) std::cout << "[" << field << "]\n";
}
