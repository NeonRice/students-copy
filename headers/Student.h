#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Human.h"

//! Class for creating Student objects, created from Human interface
class Student : public Human
{
private:
    int examGrade = 0;
    std::vector<int> grades = {};

public:
    //! Creates default valued Student object
    explicit Student();
    //! Creates a Student object from given firstName and lastName
    explicit Student(std::string fN, std::string lN);
    //! Creates a Student object from given examGrade and grade vector container
    explicit Student(double eX, std::vector<int> g);
    //! Creates a Student object from given firstName, lastName and a grade vector
    explicit Student(std::string fN, std::string lN, std::vector<int> g);
    //! Creates a Student object from given firstName, lastName, grade vector and examGrade
    explicit Student(std::string fN, std::string lN, std::vector<int> g, int exG);

    //! Default destructor
    ~Student() = default;

    //! Copy constructor
    Student(const Student &);

    //! Copy operator
    Student &operator=(const Student &);

    /** Operator+ for adding two Students with the same name,
      * returns a new Student with combined grades. */
    Student operator+(const Student &) const;
    /** Operator- for substracting two Students with the same name,
      * returns a new Student with an invalid name and grade difference
      * of the two given Student objects */
    Student operator-(const Student &) const;
    /** Operator+= for adding two Students with the same name,
      * changes and returns the Student by
      * compound adding the grades of the other Student */
    Student &operator+=(const Student &);

    //! Compares the Students by all parameters, true if equal
    bool operator==(const Student &) const;
    //! Compares the Students by all parameters, true if not same
    inline bool operator!=(const Student &other) const
    {
        return *this == other ? false : true;
    }
    //! Compares the Students by their average scores
    inline bool operator>=(const Student &other) const
    {
        return this->getAverage() >= other.getAverage();
    }
    //! Compares the Students by their average scores
    inline bool operator<=(const Student &other) const
    {
        return this->getAverage() <= other.getAverage();
    }
    //! Compares the Students by their average scores
    inline bool operator>(const Student &other) const
    {
        return this->getAverage() > other.getAverage();
    }
    //! Compares the Students by their average scores
    inline bool operator<(const Student &other) const
    {
        return this->getAverage() < other.getAverage();
    }

    //! Friend operator for output streams, prints formatted Student info
    friend std::ostream &operator<<(std::ostream &, const Student &student);
    //! Friend operator for input streams, inputs firstName and lastName into Student obj
    friend std::istream &operator>>(std::istream &, Student &student);

    //! Inherited pure virtual function from Human interface
    std::ostream &printCredentials(std::ostream &s) const;

    //! Read the first and last names with validity checks
    std::istream &readStudentName(std::istream &in = std::cin);

    /** Reads students grades from given istream with validity checks,
      * input stops when X inputted. */
    std::istream &readStudentGrades(std::istream &in = std::cin);

    /** Reads exam grade from given istream, 
     * (the 1st one entered if entered more). */
    std::istream &readExamGrade(std::istream &in = std::cin);

    //! Student Average getter
    double getAverage() const; //Returns the average of grades using the given formula

    //! Student Median getter
    double getMedian() const; //Return the median of grades

    //! Student Grade getter
    const std::vector<int> &getGrades() const;
};
