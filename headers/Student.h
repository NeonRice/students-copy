#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <tuple>

class Student
{
private:
    std::string firstName, lastName;
    int examGrade = 0;
    std::vector<int> grades = {};

public:
    explicit Student();
    explicit Student(std::string fN, std::string lN);
    explicit Student(double eX, std::vector<int> g);
    explicit Student(std::string fN, std::string lN, std::vector<int> g);
    explicit Student(std::string fN, std::string lN, std::vector<int> g, int exG);

    ~Student() = default;

    Student(const Student &);

    Student& operator=(const Student &);
    Student operator+(const Student &) const;
    Student operator-(const Student &) const;
    Student& operator+=(const Student &);

    bool operator==(const Student&) const;
    bool operator>=(const Student&) const;
    bool operator<=(const Student&) const;
    bool operator>(const Student&) const;
    bool operator<(const Student&) const;

    friend std::ostream& operator<<(std::ostream &, const Student &student);
    friend std::istream& operator>>(std::istream &, Student &student);

    std::string getFirstName() const;
    std::string getLastName() const;

    //friend void printStudentInfo(std::vector<Student> s, std::ostream &out); Don't know for now how to make it into a friend template func

    std::istream& readStudentName(std::istream &in = std::cin); //Read the first and last names with validity checks

    std::istream& readStudentGrades(std::istream &in = std::cin); //Reads students grades with validity checks, input stops when X inputted

    std::istream& readExamGrade(std::istream &in = std::cin); //Reads exam grade (the 1st one entered if entered more)

    double getAverage() const; //Returns the average of grades using the given formula

    double getMedian() const; //Return the median of grades

    const std::vector<int>& getGrades() const;
};

//void printStudentInfo(std::vector<Student> s, std::ostream &out);

