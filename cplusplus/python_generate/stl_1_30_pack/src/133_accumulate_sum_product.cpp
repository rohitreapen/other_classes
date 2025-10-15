#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
int main() {
    int a[] = {1,2,3,4};
    std::vector<int> v(a,a+4);
    int sum  = std::accumulate(v.begin(), v.end(), 0);
    int prod = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    std::cout<<sum<<" "<<prod<<"\n";
}
