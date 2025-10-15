#include <iostream>
#include <vector>
#include <algorithm>
struct LessThan3{ bool operator()(int x) const { return x<3; } };
int main() {
    int A[] = {1,2,3,4};
    std::vector<int> v(A,A+4);
    v.erase(std::remove_if(v.begin(), v.end(), LessThan3()), v.end());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
