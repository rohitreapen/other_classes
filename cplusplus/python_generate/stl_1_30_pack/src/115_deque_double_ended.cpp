#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(2); d.push_back(3); d.push_front(1);
    for (std::size_t i=0;i<d.size();++i) std::cout<<d[i]<<" ";
    std::cout<<"\n";
}
