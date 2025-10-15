#include <iostream>
#include <iterator>
#include <string>
#include <map>
int main() {
    std::istream_iterator<std::string> in(std::cin), end;
    std::map<std::string,int> freq;
    while (in != end) { ++freq[*in]; ++in; }
    for (std::map<std::string,int>::iterator it=freq.begin(); it!=freq.end(); ++it)
        std::cout<<it->first<<": "<<it->second<<"\n";
}
