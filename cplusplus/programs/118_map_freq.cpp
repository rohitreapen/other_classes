#include <iostream>
#include <map>
#include <string>
int main() {
    std::map<std::string,int> freq;
    ++freq["apple"]; ++freq["banana"]; ++freq["apple"];
    for (std::map<std::string,int>::iterator it=freq.begin(); it!=freq.end(); ++it)
        std::cout<<it->first<<": "<<it->second<<"\n";
}
