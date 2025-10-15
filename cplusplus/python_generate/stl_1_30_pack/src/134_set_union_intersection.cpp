#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main() {
    int A[] = {1,2,4}, B[] = {2,3,4};
    std::vector<int> a(A,A+3), b(B,B+3), out;
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(out));
    for (std::size_t i=0;i<out.size();++i) std::cout<<out[i]<<" "; std::cout<<"\n";
    out.clear();
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(out));
    for (std::size_t i=0;i<out.size();++i) std::cout<<out[i]<<" "; std::cout<<"\n";
}
