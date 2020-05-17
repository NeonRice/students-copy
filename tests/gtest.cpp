#include <gtest/gtest.h>
#include <list>
#include <deque>
#include <vector>

#include "../headers/Utility.h"
#include "../headers/Student.h"
#include "../headers/StudentTest.h"

namespace
{
TEST_F(StudentTest, getNameTest)
{
    ASSERT_EQ(s1->getFullName(), "Zanas Kovaliovas"); ///< Asserting since names MUST BE EQUAL to continue tests
}

TEST_F(StudentTest, getBothNamesTest)
{
    ASSERT_EQ(s1->getFullName(), s2->getFullName());
}

TEST_F(StudentTest, OperatorEqualsTest)
{
    ASSERT_TRUE(*s1 == *s2); ///< Can continue even if failure
}

TEST_F(StudentTest, OperatorNotEqualsTest)
{
    ASSERT_FALSE(*s1 != *s2);
}

TEST_F(StudentTest, OperatorPlusEqualsTest)
{
    std::vector<int> grades = {5, 8}, expectedGrades = {5, 8, 10};
    Student s(s1->getFirstName(), s1->getLastName(), grades);

    s += *s1;
    auto newGrades = s.getGrades();

    EXPECT_EQ(newGrades, expectedGrades);
}

TEST_F(StudentTest, OperatorPlusTest)
{
    std::vector<int> expectedGrades = {10, 10};
    Student expectedStudent(s1->getFirstName(), s1->getLastName(), expectedGrades);

    EXPECT_TRUE((*s1 + *s2) == expectedStudent);
}

TEST_F(StudentTest, OperatorMinusTest)
{
    std::vector<int> expectedGrades = {}; // 1 grade - 1 grade that are same = 0
    Student s = *s1 - *s2, expectedStudent = Student(0, expectedGrades);

    EXPECT_TRUE(s.getGrades().size() == expectedStudent.getGrades().size());
}

TEST_F(StudentTest, OperatorMinusTest2)
{
    std::vector<int> grades = {10, 5, 6};
    Student s("Zanas", "Kovaliovas", grades);

    Student expectedStudent = s - *s1;
    auto resultGrades = expectedStudent.getGrades();

    EXPECT_TRUE(grades[1] == resultGrades[0] && grades[2] == resultGrades[1]);
}

TEST_F(StudentTest, OperatorGreaterThanTest)
{
    const std::vector<int> lowerGrades = {1}, higherGrades = {10};
    const double examGrade = 10; //Same exam grade for both

    Student s1(examGrade, lowerGrades), s2(examGrade, higherGrades);
    EXPECT_TRUE(s2 > s1);
}

TEST_F(StudentTest, getMedianTest)
{
    std::vector<int> gradesMiddle = {1, 2, 3}, gradesMiddleAverage = {2, 5, 10, 10, 10, 10};
    Student s1("Zanas", "Kovaliovas", gradesMiddle), s2("Zanas", "Kovaliovas", gradesMiddleAverage);

    EXPECT_TRUE(s1.getMedian() == 2 && s2.getMedian() == 10);
}

TEST(UtilityTest, seperateContainersVectorTest)
{
    std::vector<int> g1{1, 1, 1, 1}, g2{2, 2, 2, 2}, g3{5, 5, 5, 5};
    std::vector<Student> students{Student(4, g1), Student(4, g2), Student(6, g3)}, weakStudents;
    seperateContainer(students, weakStudents);
    bool PASSED_TEST = passedSeperationTest(students, weakStudents);

    EXPECT_TRUE(PASSED_TEST);
}

TEST(UtilityTest, seperateContainersDequeTest)
{
    std::vector<int> g1{1, 1, 1, 1}, g2{2, 2, 2, 2}, g3{5, 5, 5, 5};
    std::deque<Student> students{Student(4, g1), Student(4, g2), Student(6, g3)}, weakStudents;
    seperateContainer(students, weakStudents);
    bool PASSED_TEST = passedSeperationTest(students, weakStudents);

    EXPECT_TRUE(PASSED_TEST);
}

TEST(UtilityTest, seperateContainersListTest)
{
    std::vector<int> g1{1, 1, 1, 1}, g2{2, 2, 2, 2}, g3{5, 5, 5, 5};
    std::list<Student> students{Student(4, g1), Student(4, g2), Student(6, g3)}, weakStudents;
    seperateContainer(students, weakStudents);
    bool PASSED_TEST = passedSeperationTest(students, weakStudents);

    EXPECT_TRUE(PASSED_TEST);
}

} // namespace