#include <iostream>
#include <bitset>
#include <string>
int main() {
    std::bitset<8> b(std::string("00010110"));
    std::cout<<"bits set = "<<b.count()<<"\n";
    std::cout<<"b[1] = "<<b[1]<<"\n";
    b.flip(2);
    std::cout<<b<<"\n";
}
