#include <iostream>
#include <vector>
int main() {
    std::vector<int> v;
    v.push_back(3); v.push_back(1); v.push_back(4);
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
