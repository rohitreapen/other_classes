#include <iostream>
#include <string>

int main()
{
    std::string s;
    
    std::cout << "Enter word: ";
    std::getline(std::cin, s);

    std::size_t j = s.size();
    if (j)
    {
        j--;
    }
    else
    {
        std::cout << "Empty string" << std::endl;
        return 0;
    }
    for (std::size_t i=0; i < j && j >= 0; ++i, --j)
    {
        char t=s[i]; 
        s[i]=s[j];
        s[j]=t;
    }
    std::cout << s << std::endl;

    return 0;
}