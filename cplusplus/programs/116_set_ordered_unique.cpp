#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(3); s.insert(1); s.insert(3);
    for (std::set<int>::iterator it=s.begin(); it!=s.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}
