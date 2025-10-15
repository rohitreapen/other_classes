#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    
    std::cout<<"Line: ";
    std::getline(std::cin, s);

    int v = 0, c = 0;
    for (std::size_t i = 0; i < s.size(); ++i)
    {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        if (std::isalpha(ch))
        {
            ch = static_cast<unsigned char>(std::tolower(ch));

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch=='o' || ch == 'u') 
                ++v;
            else
                ++c;
        }
    }

    std::cout << "vowels=" << v << " consonants=" << c << std::endl;

    return 0;
}