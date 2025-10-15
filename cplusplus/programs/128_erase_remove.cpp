#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {1,2,3,2,4};
    std::vector<int> v(a,a+5);
    v.erase(std::remove(v.begin(), v.end(), 2), v.end());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
