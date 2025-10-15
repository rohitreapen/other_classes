#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
int up(int c){ return std::toupper((unsigned char)c); }
int main() {
    std::string s="MiT";
    std::transform(s.begin(), s.end(), s.begin(), up);
    std::cout<<s<<"\n";
}
