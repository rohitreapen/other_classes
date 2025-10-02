#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "Enter your move (r/p/s): ";
    char you;
    std::cin >> you;
    int comp = std::rand() % 3;
    std::cout << std::rand() << std::endl;
    char mv[3] = {'r','p','s'};
    char c = mv[comp];

    std::cout << "Computer: " << c << std::endl;
    if (you == c)
      std::cout << "Draw" << std::endl;
    else if ((you=='r' && c=='s') || (you=='p' && c=='r') || (you=='s' && c=='p'))
        std::cout << "You win!" << std::endl;
    else
        std::cout << "You lose!" << std::endl;

    return 0;
}
