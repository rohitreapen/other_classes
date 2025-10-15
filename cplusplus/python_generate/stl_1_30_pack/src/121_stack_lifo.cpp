#include <iostream>
#include <stack>
int main() {
    std::stack<int> st;
    st.push(10); st.push(20);
    std::cout<<st.top()<<"\n";
    st.pop();
    std::cout<<st.top()<<"\n";
}
