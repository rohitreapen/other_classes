#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {3,1,3,2,2,1};
    std::vector<int> v(a,a+6);
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
