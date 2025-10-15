#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int a[] = {1,3,3,7};
    std::vector<int> v(a,a+4);
    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 3);
    if (it!=v.end()) std::cout<<"first 3 at index "<<(it - v.begin())<<"\n";
    std::cout<<"count(3) = "<<std::count(v.begin(), v.end(), 3)<<"\n";
}
