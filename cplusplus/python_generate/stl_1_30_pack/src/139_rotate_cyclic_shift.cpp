#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int A[] = {1,2,3,4,5};
    std::vector<int> v(A,A+5);
    std::rotate(v.begin(), v.begin()+2, v.end()); // [1,2|3,4,5] -> [3,4,5,1,2]
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
