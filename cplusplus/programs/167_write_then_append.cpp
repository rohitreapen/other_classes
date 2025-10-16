#include <fstream>
#include <iostream>
int main() {
    { std::ofstream a("log26.txt"); a << "First\n"; }
    { std::ofstream b("log26.txt", std::ios::app); b << "Second\n"; }
}
