#include "Student.h"

// Comparison inline functions
//! Utiltiy function that compares Student objects by grades
inline bool compareByFinalGrade(Student &a, Student &b) //Comparison Utility function
{
    return a.getAverage() > b.getAverage();
}

//A comparison function here for strong and weak students
//! Comparison function for weak Students
inline bool IsWeakStudent(Student &s) { return ((s.getAverage() < 5.0) == 0); }
//! Comparison function for strong Students
inline bool IsStrongStudent(Student &s) { return ((s.getAverage() >= 5.0) == 0); }

//Container seperation algorithms
//! Template function to seperate a sorted Container
template <typename Container>
void seperateSortedContainer(Container &students, Container &weakStudents) // Vector must be sorted in decreasing grade order in order for the function to work correctly
{
    auto it = students.begin();
    auto b = students.begin();
    for (; it != students.end(); ++it)
    {
        if ((*it).getAverage() < 5.0)
            weakStudents.push_back(*it);
        if ((*it).getAverage() >= 5.0)
            b = it;
    }
    students.erase(b, it);
}

//! Template function for seperation method 1, look @ README
template <typename Container>
void seperateContainer1(Container &students, Container &weakStudents, Container &newStudents)
{
    std::remove_copy_if(students.begin(), students.end(), std::back_inserter(weakStudents), IsWeakStudent);
    std::remove_copy_if(students.begin(), students.end(), std::back_inserter(newStudents), IsStrongStudent);
}

//! Template function for seperation method 2, look @ README
template <typename Container>
void seperateContainer2(Container &students, Container &weakStudents, Container &goodStudents) //Faster than seperateContainer2
{
    auto it = students.begin();
    for (; it != students.end(); ++it)
    {
        if ((*it).getAverage() < 5.0)
            weakStudents.push_back(*it);
        if ((*it).getAverage() >= 5.0)
            goodStudents.push_back(*it);
    }
}

//! The most efficient seperation algorithm that is being used, look @ README
template <typename Container>
void seperateContainer(Container &students, Container &weakStudents)
{
    std::remove_copy_if(students.begin(), students.end(), std::back_inserter(weakStudents), IsWeakStudent);
    students.erase(
        std::remove_if(students.begin(), students.end(), IsStrongStudent),
        students.end());
}