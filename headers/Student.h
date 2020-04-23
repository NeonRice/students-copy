#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

class Student
{
private:
    std::string firstName, lastName;
    int examGrade;
    std::vector<int> grades;

public:
    explicit Student();
    explicit Student(std::string fN, std::string lN);
    explicit Student(double eX, std::vector<int> g);
    explicit Student(std::string fN, std::string lN, std::vector<int> g);
    explicit Student(std::string fN, std::string lN, std::vector<int> g, int exG);

    ~Student();

    std::string getFirstName() const;
    std::string getLastName() const;

    friend void printStudentInfo(std::vector<Student> s, std::ostream &out);

    void readStudentName(); //Read the first and last names with validity checks

    void readStudentGrades(); //Reads students grades with validity checks, input stops when X inputted

    void readExamGrade(); //Reads exam grade (the 1st one entered if entered more)

    double getAverage(); //Returns the average of grades using the given formula

    double getMedian(); //Return the median of grades
};

void printStudentInfo(std::vector<Student> s, std::ostream &out);

void printStudentInfoToFile(std::vector<Student> s);
