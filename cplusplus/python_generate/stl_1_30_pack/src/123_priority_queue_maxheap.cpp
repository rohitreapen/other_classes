#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq;
    pq.push(5); pq.push(1); pq.push(9);
    while(!pq.empty()){ std::cout<<pq.top()<<" "; pq.pop(); }
    std::cout<<"\n";
}
