#include "../headers/Student.h"
#include "../headers/Input.h"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

Student::Student() {}
Student::Student(std::string fN, std::string lN) : Human(fN, lN) {}
Student::Student(double eX, std::vector<int> g) : examGrade(eX), grades(g) {}
Student::Student(std::string fN, std::string lN, std::vector<int> g)
    : Human(fN, lN), grades(g) {}
Student::Student(std::string fN, std::string lN, std::vector<int> g, int exG)
    : Human(fN, lN), grades(g), examGrade(exG) {}

// Copy constructor
Student::Student(const Student &other)
{
    firstName = other.firstName;
    lastName = other.lastName;
    grades = other.grades;
    examGrade = other.examGrade;
}

// Operator overloading
Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        firstName = other.firstName;
        lastName = other.lastName;
        grades = other.grades;
        examGrade = other.examGrade;
    }

    return *this;
}

bool Student::operator==(const Student &other) const
{
    if (grades.size() == other.grades.size())
    {
        auto it2 = other.grades.begin();
        for (auto it = grades.begin(); it != grades.end(); ++it, ++it2)
        {
            if (*it != *it2)
                return false;
        }
    }
    else
        return false;
    if (firstName == other.firstName && 
        lastName == other.lastName && 
        examGrade == other.examGrade)
        return true;
    else
        return false;
}

Student Student::operator+(const Student &other) const
{
    if (this->getFullName() == other.getFullName())
    {
        Student student(*this);
        student.grades.insert(
            student.grades.end(),
            other.grades.begin(),
            other.grades.end());

        return student;
    }
    return *this;
}

Student Student::operator-(const Student &other) const
{
    if (this->getFullName() == other.getFullName())
    {
        std::vector<int> difference;
        std::vector<int> v1 = this->grades;
        std::vector<int> v2 = other.grades;

        std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                            std::inserter(difference, difference.begin()));

        return Student("----", "----", difference);
    }
    return *this;
}

Student &Student::operator+=(const Student &other)
{
    this->grades.insert(
        this->grades.end(),
        other.grades.begin(),
        other.grades.end());

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Student &student)
{
    out << std::left << std::setw(20) << student.getFirstName() << std::left
        << std::setw(20) << student.getLastName() << std::left << std::setw(8) << std::fixed
        << std::setprecision(2) << student.getAverage() << student.getMedian();

    return out;
}

std::istream &operator>>(std::istream &in, Student &student)
{
    in >> student.firstName >> student.lastName;

    return in;
}

std::istream &Student::readStudentName(std::istream &in)
{
    std::string first = "", last = "";
    std::size_t ch;
    do
    {
        std::cout << "Enter full student name: ";
        std::cin >> first >> last;
        std::string fullName = first + last;
        ch = fullName.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    } while (ch != std::string::npos);
    firstName = first;
    lastName = last;

    return in;
}

std::istream &Student::readStudentGrades(std::istream &in)
{
    std::cout << "Enter student grades:" << std::endl;
    std::string b;
    while (in >> b && b != "x" && b != "X")
    {
        int c;
        try
        {
            c = std::stoi(b);
        }
        catch (const std::exception &e)
        {
            std::cout << "Invalid argument skipped. Insert only ints" << std::endl;
            continue;
        }
        if (c < 0 || c > 10) //Skipping invalid grades
            continue;
        grades.push_back(c);
    }
    
    return in;
}

std::istream &Student::readExamGrade(std::istream &in)
{
    std::string b;
    int c;
    while (in >> b)
    {
        try
        {
            c = std::stoi(b);
        }
        catch (const std::exception &e)
        {
            continue;
        }
        if (c < 0 || c > 10)
            continue;
        break;
    }
    examGrade = c;

    return in;
}

double Student::getAverage() const
{
    if (grades.size() == 0)
        return 0;

    double gradeSum = 0;
    for (size_t i = 0; i < grades.size(); i++)
    {
        gradeSum += grades[i];
    }
    return (double)(gradeSum / grades.size()) * 0.4 + 0.6 * (double)examGrade;
}

double Student::getMedian() const
{
    std::vector<int> grade_copy = grades;
    if (grades.size() == 0)
        return 0;

    std::sort(grade_copy.begin(), grade_copy.end());
    if (grade_copy.size() % 2)
    {
        return grade_copy[grade_copy.size() / 2];
    }
    else
    {
        return ((double)grade_copy[grade_copy.size() / 2] 
        + grade_copy[(grade_copy.size() / 2) - 1]) / 2;
    }
}

std::ostream &Student::printCredentials(std::ostream &out) const
{
    out << std::left << std::setw(20) << this->getFirstName() << std::left
        << std::setw(20) << this->getLastName() << std::left << std::setw(8) << std::fixed
        << std::setprecision(2) << this->getAverage() << this->getMedian();

    return out;
}

// Return READ-ONLY vector of grades
const std::vector<int> &Student::getGrades() const { return grades; }
