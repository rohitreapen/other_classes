#include <iostream>
#include <utility>
#include <string>
int main() {
    std::pair<std::string,int> p = std::make_pair(std::string("id"), 42);
    std::cout<<p.first<<" "<<p.second<<"\n";
}
