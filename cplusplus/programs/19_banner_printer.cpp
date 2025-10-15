#include <iostream>

void banner(const std::string& title); // prototype

int main()
{
    banner("Welcome to the Function Show!");
    banner("Let's begin");

    return 0;
}

void banner(const std::string& title)
{
    std::cout << "==== " << title << " ====\n";
}