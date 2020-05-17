#include "../headers/Input.h"
#include <chrono>

//Utility Functions

bool yesOrNo(const std::string &instruction)
{
    std::cout << instruction << std::endl;
    char choice;
    while (1)
    {
        std::cin >> choice;
        if (toupper(choice) == 'Y')
            return true;
        else if (toupper(choice) == 'N')
            return false;
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input! Try again!" << std::endl;
        }
    }
}
