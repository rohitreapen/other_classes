#include <iostream>
#include <vector>
#include <algorithm>
struct IsOdd{ bool operator()(int x) const { return x%2==1; } };
int main() {
    int A[] = {1,2,3,4,5};
    std::vector<int> v(A,A+5);
    std::replace(v.begin(), v.end(), 2, 20);
    std::replace_if(v.begin(), v.end(), IsOdd(), 99);
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
