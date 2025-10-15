#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
struct ByLen {
    bool operator()(const std::string& a, const std::string& b) const {
        if (a.size()!=b.size()) return a.size()<b.size();
        return a<b;
    }
};
int main() {
    std::string a[] = {"bb","a","ccc","aa"};
    std::vector<std::string> v(a,a+4);
    std::stable_sort(v.begin(), v.end(), ByLen());
    for (std::size_t i=0;i<v.size();++i) std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
