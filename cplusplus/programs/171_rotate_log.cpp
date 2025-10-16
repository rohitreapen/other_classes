#include <fstream>
#include <iostream>
#include <string>
int main() {
    {   std::ifstream in("log30.txt");
        std::ofstream out("app30.bak");
        if (in && out) {
            std::string line;
            while (std::getline(in, line)) out << line << "\n";
        }
    }
    {   std::ofstream trunc("log30.txt", std::ios::trunc);
        if (trunc) trunc << "Log rotated.\n";
    }
}
