#include <iostream>
#include <string>

std::string repeat(const std::string& s, int n)
{
    std::string out;
    for (int i=0; i<n; ++i)
        out += s;

    return out;
}

int main()
{ 
    std::string s;
    int n;
    
    std::cout << "Enter word and n: ";    
    std::cin >>s >> n;
    
    std::cout << repeat(s,n) << std::endl;

    return 0;
}