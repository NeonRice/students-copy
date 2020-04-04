#include "headers/Student.h"
#include "headers/Input.h"

Student::Student() {}
Student::Student(std::string fN, std::string lN) : firstName(fN), lastName(lN) {}
Student::Student(double eX, std::vector<int> g) : examGrade(eX), grades(g) {}
Student::Student(std::string fN, std::string lN, std::vector<int> g)
    : firstName(fN), lastName(lN), grades(g) {}
Student::Student(std::string fN, std::string lN, std::vector<int> g, int exG)
    : firstName(fN), lastName(lN), grades(g), examGrade(exG) {}

std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }

void Student::readStudentName() //Read the first and last names with validity checks
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
}

void Student::readStudentGrades() //Reads students grades with validity checks, input stops when X inputted
{
    std::cout << "Enter student grades:" << std::endl;
    std::string b;
    while (std::cin >> b && b != "x" && b != "X")
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
}

void Student::readExamGrade() //Reads exam grade (the 1st one entered if entered more)
{
    std::string b;
    int c;
    std::cout << "Enter student exam grade: ";
    while (std::cin >> b)
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
}

double Student::getAverage() //Returns the average of grades using the given formula
{
    double gradeSum = 0;
    for (size_t i = 0; i < grades.size(); i++)
    {
        gradeSum += grades[i];
    }
    return (double)(gradeSum / grades.size()) * 0.4 + 0.6 * (double)examGrade;
}

double Student::getMedian() //Return the median of grades
{
    std::sort(grades.begin(), grades.end());
    if (grades.size() % 2)
    {
        return ((double)grades[grades.size() / 2] + grades[(grades.size() / 2) - 1]) / 2;
    }
    else
    {
        return grades[grades.size() / 2];
    }
}

//Friend function (Dont know how to make it into a friend template function)
// void printStudentInfo(std::vector<Student> s, std::ostream &out) //Formatted output to console
// {
//     out << std::left << std::setw(20) << "Last Name" << std::left << std::setw(20) << "First Name" << std::left << std::setw(8) << "Average" <<  "Median" << std::endl;
//     out << "---------------------------------------------------------------------------------------------------------------" << std::endl;
//     for (size_t i = 0; i < s.size(); i++)
//     {
//         out << std::left << std::setw(20) << s[i].getLastName() << std::left << std::setw(20) << s[i].getFirstName() <<  std::left << std::setw(8) << std::fixed << std::setprecision(2) << s[i].getAverage() << s[i].getMedian() << std::endl;
//     }
// }
