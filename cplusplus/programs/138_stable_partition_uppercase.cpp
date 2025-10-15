#include <iostream>
#include <algorithm>
#include <string>
struct IsUpper{ bool operator()(char c) const { return c>='A' && c<='Z'; } };
int main() {
    std::string s="aAbBcC";
    std::stable_partition(s.begin(), s.end(), IsUpper());
    std::cout<<s<<"\n"; // "ABCabc"
}
