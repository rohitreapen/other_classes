#include <iostream>
#include <map>
#include <string>
#include <functional>
int main() {
    std::map<int,std::string, std::greater<int> > m;
    m[2]="two"; m[1]="one"; m[3]="three";
    for (std::map<int,std::string,std::greater<int> >::iterator it=m.begin(); it!=m.end(); ++it)
        std::cout<<it->first<<" : " << it->second << std::endl;
    std::cout<<"\n";
}
