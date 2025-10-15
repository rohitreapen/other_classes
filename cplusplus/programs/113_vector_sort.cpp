#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a[] = {5,2,9,1};

    std::vector<int> v(a, a+4);

    std::sort(v.begin(), v.end());

    for (std::size_t i=0;i<v.size();++i)
        std::cout<<v[i]<<" ";
    std::cout<<"\n";

    std::sort(v.begin(), v.end(), std::greater<int>());

    for (std::size_t i=0;i<v.size();++i)
        std::cout<<v[i]<<" ";
    std::cout<<"\n";

    return 0;
}
