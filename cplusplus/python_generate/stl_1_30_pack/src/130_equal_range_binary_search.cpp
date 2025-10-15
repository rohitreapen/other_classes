#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {1,2,2,2,5};
    std::vector<int> v(a,a+5);
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> r =
        std::equal_range(v.begin(), v.end(), 2);
    std::cout<<"2s in ["<<(r.first - v.begin())<<", "<<(r.second - v.begin())<<")\n";
}
