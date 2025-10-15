#include <iostream>

char letter(int s) 
{
    if (s >= 90) 
        return 'A'; 
    if (s >= 80) 
        return 'B';
    if (s >= 70) 
        return 'C'; 
    if (s >= 60) 
        return 'D';

    return 'F';
}

int main()
{ 
    int s; 
    std::cout << "score: "; 
    std::cin >> s;
    
    std::cout << letter(s) << std::endl;

    return 0;
}