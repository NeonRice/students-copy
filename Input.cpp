#include "headers/Input.h"
#include <chrono>

//Utility Functions

bool yesOrNo(const std::string &instruction)
{
    std::cout << instruction << std::endl;
    char choice;
    while (1)
    {
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y')
            return true;
        else if (choice == 'N' || choice == 'n')
            return false;
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input! Try again!" << std::endl;
        }
    }
}

