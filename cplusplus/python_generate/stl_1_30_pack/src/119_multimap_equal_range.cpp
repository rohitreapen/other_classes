#include <iostream>
#include <map>
#include <string>
#include <utility>
int main() {
    std::multimap<std::string,int> mm;
    mm.insert(std::make_pair("grp",1));
    mm.insert(std::make_pair("grp",2));
    mm.insert(std::make_pair("other",9));
    std::pair<std::multimap<std::string,int>::iterator,
              std::multimap<std::string,int>::iterator> r = mm.equal_range("grp");
    for (std::multimap<std::string,int>::iterator it=r.first; it!=r.second; ++it)
        std::cout<<it->second<<" ";
    std::cout<<"\n";
}
