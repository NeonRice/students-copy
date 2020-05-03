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

// Copy constructor
Student::Student(const Student &other)
{
    firstName = other.firstName;
    lastName = other.lastName;
    grades = other.grades;
    examGrade = other.examGrade;
}

// Operator overloading
Student& Student::operator=(const Student &other)
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
    if(grades.size() == other.grades.size())
    {
        auto it2 = other.grades.begin();
        for(auto it = grades.begin(); it != grades.end(); ++it, ++it2)
        {
            if(*it != *it2)
                return false;
        }
    }
    else
        return false;
    if(firstName == other.firstName && lastName == other.lastName && examGrade == other.examGrade)
        return true;
    else return false;
}

inline bool Student::operator>=(const Student &other) const
{
    if (this->getAverage() >= other.getAverage())
        return true;
    else return false;
}

inline bool Student::operator<=(const Student &other) const
{
    if (this->getAverage() <= other.getAverage())
        return true;
    else return false;
}

inline bool Student::operator>(const Student &other) const
{
    if (this->getAverage() > other.getAverage())
        return true;
    else return false;
}

inline bool Student::operator<(const Student &other) const
{
    if (this->getAverage() < other.getAverage())
        return true;
    else return false;
}

Student Student::operator+(const Student &other) const
{
    if(*this == other)
    {
        Student student(*this);
        student.grades.insert(
            student.grades.end(),
            other.grades.begin(),
            other.grades.end()
        );

        return student;
    }
}

Student Student::operator-(const Student &other) const
{
    if(*this == other)
    {
        std::vector<int> xvec = this->grades;
        std::vector<int> yvec = other.grades;

        std::set<std::tuple<int,int> > set;
        for (std::size_t i = 0; i < xvec.size();) {
            if (set.emplace(xvec[i], yvec[i]).second) {
                i++;
            } else {
                xvec.erase(xvec.begin() + i);
                yvec.erase(yvec.begin() + i);
            }
        }
        xvec.insert(
            xvec.end(),
            yvec.begin(),
            yvec.end()
        );
        Student("", "", xvec);
    }
}

Student& Student::operator+=(const Student &other)
{
    this->grades.insert(
            this->grades.end(),
            other.grades.begin(),
            other.grades.end()
        );

    return *this;
}

std::ostream& operator<<(std::ostream &out, const Student &student)
{
    out << std::left << std::setw(20) << student.getFirstName() << std::left
        << std::setw(20) << student.getLastName() << std::left << std::setw(8) << std::fixed
        << std::setprecision(2) << student.getAverage() << student.getMedian();

    return out;
}

std::istream& operator>>(std::istream &in, Student &student)
{
    in >> student.firstName >> student.lastName;

    return in;
}

std::istream& Student::readStudentName(std::istream &in) //Read the first and last names with validity checks
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

std::istream& Student::readStudentGrades(std::istream &in) //Reads students grades with validity checks, input stops when X inputted
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
}

std::istream& Student::readExamGrade(std::istream &in) //Reads exam grade (the 1st one entered if entered more)
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

double Student::getAverage() const //Returns the average of grades using the given formula
{
    double gradeSum = 0;
    for (size_t i = 0; i < grades.size(); i++)
    {
        gradeSum += grades[i];
    }
    return (double)(gradeSum / grades.size()) * 0.4 + 0.6 * (double)examGrade;
}

double Student::getMedian() const//Return the median of grades
{
    std::vector<int> grade_copy = grades;
    std::sort(grade_copy.begin(), grade_copy.end());
    if (grade_copy.size() % 2)
    {
        return ((double)grade_copy[grade_copy.size() / 2] + grade_copy[(grade_copy.size() / 2) - 1]) / 2;
    }
    else
    {
        return grade_copy[grade_copy.size() / 2];
    }
}

// Return READ-ONLY vector of grades
const std::vector<int>& Student::getGrades() const { return grades;} 



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
