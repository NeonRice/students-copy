#pragma once

#include <fstream>
#include <iomanip>

template <typename Container>
void printStudentInfo(Container &s, std::ostream &out) //Formatted output to console
{
    out << std::left << std::setw(20) << "Last Name" << std::left << std::setw(20) << "First Name" << std::left << std::setw(8) << "Average"
        << "Median" << std::endl;
    out << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        out << *it << std::endl;
    }
}

//Student generation function

void generateTestFile(int generationAmount, int gradeCount);