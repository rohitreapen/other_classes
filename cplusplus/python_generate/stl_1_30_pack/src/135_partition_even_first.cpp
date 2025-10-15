#include <iostream>
#include <vector>
#include <algorithm>
struct IsEven{ bool operator()(int x) const { return x%2==0; } };
int main() {
    int A[] = {1,2,3,4,5,6};
    std::vector<int> v(A,A+6);
    std::partition(v.begin(), v.end(), IsEven());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
