#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Human.h"


class Student : public Human
{
private:
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
    inline bool operator!=(const Student &other) const { return *this == other ? false : true; }
    inline bool operator>=(const Student &other) const { return this->getAverage() >= other.getAverage(); }
    inline bool operator<=(const Student &other) const { return this->getAverage() <= other.getAverage(); }
    inline bool operator>(const Student &other) const { return this->getAverage() > other.getAverage(); }
    inline bool operator<(const Student &other) const { return this->getAverage() < other.getAverage(); }

    friend std::ostream& operator<<(std::ostream &, const Student &student);
    friend std::istream& operator>>(std::istream &, Student &student);

    std::ostream& printCredentials(std::ostream& s) const; 

    std::istream& readStudentName(std::istream &in = std::cin); //Read the first and last names with validity checks

    std::istream& readStudentGrades(std::istream &in = std::cin); //Reads students grades with validity checks, input stops when X inputted

    std::istream& readExamGrade(std::istream &in = std::cin); //Reads exam grade (the 1st one entered if entered more)

    double getAverage() const; //Returns the average of grades using the given formula

    double getMedian() const; //Return the median of grades

    const std::vector<int>& getGrades() const;
};

