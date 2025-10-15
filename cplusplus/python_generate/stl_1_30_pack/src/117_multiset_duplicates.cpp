#include <iostream>
#include <set>
int main() {
    std::multiset<int> ms;
    ms.insert(3); ms.insert(1); ms.insert(3);
    std::cout<<"count(3)="<<ms.count(3)<<"\n";
}
