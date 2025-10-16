#include <fstream>
#include <iostream>
int main() {
    std::ifstream in("dst.txt");
    if (!in) { std::cerr << "open fail\n"; return 1; }
    int c = in.peek();
    if (c != EOF) std::cout << "peek:" << char(c) << "\n";
    in.ignore(1);
    char ch;
    if (in.get(ch)) std::cout << "get:" << ch << "\n";
    in.putback(ch);
    if (in.get(ch)) std::cout << "get again:" << ch << "\n";
}
