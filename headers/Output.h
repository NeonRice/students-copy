#pragma once

#include <fstream>

template <typename Container>
void printStudentInfo(Container &s, std::ostream &out) //Formatted output to console
{
    out << std::left << std::setw(20) << "Last Name" << std::left << std::setw(20) << "First Name" << std::left << std::setw(8) << "Average"
        << "Median" << std::endl;
    out << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        out << std::left << std::setw(20) << (*i).getLastName() << std::left << std::setw(20) << (*i).getFirstName() << std::left << std::setw(8) << std::fixed << std::setprecision(2) << (*i).getAverage() << (*i).getMedian() << std::endl;
    }
}