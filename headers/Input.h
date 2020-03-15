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
#include <stdexcept>

const int MAX_GRADES = 30; //Max amount of grades

const std::string FILE_NAME = "students.txt";

std::vector<Student> readStudents();         //     Basically all the start-input logic is handled in this function
std::vector<Student> readStudentsFromFile(std::string fileName = "students.txt", bool sortByName = true); //  Function to read from file


bool yesOrNo(const std::string &);
