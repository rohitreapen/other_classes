#include <iostream>
#include <list>
int main() {
    std::list<int> L;
    L.push_back(2); L.push_front(1); L.push_back(3);
    for (std::list<int>::iterator it=L.begin(); it!=L.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}
