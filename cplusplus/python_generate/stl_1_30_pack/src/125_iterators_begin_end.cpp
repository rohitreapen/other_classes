#include <iostream>
#include <vector>
int main() {
    int a[] = {3,1,4};
    std::vector<int> v(a,a+3);
    for (std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}
