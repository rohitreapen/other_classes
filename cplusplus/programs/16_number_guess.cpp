#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int target = 1 + std::rand() % 100;

    std::cout << "Guess my number (1..100)" << std::endl;
    int tries = 0, x;

    for (std::cout << "Your guess: "; std::cin >> x; std::cout << "Your guess: ")
    {
      ++tries;
      if (x < target)
        std::cout << "Too low!" << std::endl;
      else if (x > target)
        std::cout << "Too high!" << std::endl;
      else
      {
        std::cout << "Correct in " << tries << " tries." << std::endl;
        break;
      }
    }
}
