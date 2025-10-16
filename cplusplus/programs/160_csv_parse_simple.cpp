#include <fstream>
#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ifstream in("username.csv");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    std::string line;
    while (std::getline(in, line)) {
        std::vector<std::string> fields;
        std::string cur;
        for (std::size_t i=0;i<line.size();++i) {
            if (line[i]==';'){ fields.push_back(cur); cur.clear(); }
            else cur += line[i];
        }
        fields.push_back(cur);
        for (std::size_t i=0;i<fields.size();++i)
            std::cout << "[" << fields[i] << "]";
        std::cout << "\n";
    }
}
