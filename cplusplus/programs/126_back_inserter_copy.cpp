#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main() {
    int a[] = {1,2,3};
    std::vector<int> v;
    std::copy(a, a+3, std::back_inserter(v));
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
