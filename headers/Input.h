#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <random>
#include <fstream>
#include "Student.h"

const int MAX_GRADES = 100; //Max amount of grades

const std::string FILE_NAME = "students.txt";
const std::string OUT_FILE_NAME = "studentsOutput.txt";

std::vector<Student> readStudents(); //     Basically all the start-input logic is handled in this function
std::vector<Student> readStudentsFromFile();    //  Function to read from file

bool yesOrNo(const std::string&);
