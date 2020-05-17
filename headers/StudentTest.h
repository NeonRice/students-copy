#pragma once

#include "Student.h"

#include <vector>
#include <gtest/gtest.h>

//! Test Fixture class for Student class tests
class StudentTest : public ::testing::Test
{
protected:
    Student *s1;
    Student *s2;
    std::vector<int> grades;

    virtual void SetUp()
    {
        grades.push_back(10);
        s1 = new Student("Zanas", "Kovaliovas", grades);
        s2 = new Student("Zanas", "Kovaliovas", grades);
    }

    virtual void TearDown()
    {
        delete s1;
        delete s2;
    }
};

//! Helper utiltiy testing function for container tests
template <typename Container>
bool passedSeperationTest(Container students, Container weakStudents)
{
    bool PASSED_TEST = true;
    for(auto student : students)
    {
        if(student.getAverage() < 5.0)
            PASSED_TEST = false;
    }
    for(auto student : weakStudents)
    {
        if(student.getAverage() > 5.0)
            PASSED_TEST = true;
    }
    return PASSED_TEST;
}