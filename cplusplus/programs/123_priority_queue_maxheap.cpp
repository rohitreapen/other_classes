#include <iostream>
#include <queue>

#include <functional>

int main() {
    std::priority_queue<int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(9);

    while(!pq.empty()){ std::cout<<pq.top()<<" "; pq.pop(); }
    std::cout<<"\n";

    std::priority_queue<int, std::vector<int>, std::greater<int> > minq;
    minq.push(5);
    minq.push(1);
    minq.push(9);

    while(!pq.empty()){ std::cout<<pq.top()<<" "; pq.pop(); }
    std::cout<<"\n";

    return 0;
}
