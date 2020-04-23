#include "headers/Output.h"
#include <iomanip>

void generateTestFile(int generationAmount, int gradeCount)
{
    //Generating labels
    std::ofstream file("students" + std::to_string(generationAmount) + ".txt");
    file << std::left << std::setw(18) << "Vardas" << std::setw(18) << "Pavarde";
    for (int i = 1; i <= gradeCount; ++i)
        file << std::left << "ND" << std::setw(10) << i;
    file << "Egz." << std::endl;

    for (int i = 1; i <= generationAmount; ++i)
    {
        file << std::left << "Vardas" << std::setw(12) << i << "Pavarde" << std::setw(12) << i;
        for (int i = 0; i <= gradeCount; ++i)
            file << std::setw(12) << rand() % 10 + 1;
        file << std::endl;
    }
}