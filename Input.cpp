#include "headers/Input.h"

//Utility Functions

bool yesOrNo(const std::string &instruction)
{
    std::cout << instruction << std::endl;
    char choice;
    while (1)
    {
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y')
            return true;
        else if (choice == 'N' || choice == 'n')
            return false;
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input! Try again!" << std::endl;
        }
    }
}

inline bool compareByLastName(const Student &a, const Student &b)
{
    return a.getLastName() < b.getLastName();
}

//Input Functions

std::vector<Student> readStudents() //Basically all the start-input logic is handled in this function
{
    int studNum = 0;
    std::vector<Student> students;
    std::cout << "How many students do you want to input?: ";
    std::cin >> studNum;
    while (1)
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input! Try again." << std::endl;
            std::cin >> studNum;
        }
        if (!std::cin.fail())
            break;
    }

    bool randomGrades = yesOrNo("Generate random grades and exam score? (Y OR N): ");
    if (randomGrades)
    {
        for (size_t i = 0; i < studNum; i++)
        {
            std::vector<int> grades;
            int examGrade = rand() % 10 + 1;
            int gradeNum = rand() % MAX_GRADES + 1;
            for (int i = 0; i < gradeNum; ++i)
                grades.push_back(rand() % 10 + 1);
            Student s(examGrade, grades);
            s.readStudentName();
            students.push_back(s);
        }
    }
    else
    {
        for (size_t i = 0; i < studNum; i++)
        {
            Student s;
            s.readStudentName();
            s.readStudentGrades();
            s.readExamGrade();
            students.push_back(s);
        }
    }

    return students;
}

std::vector<Student> readStudentsFromFile()
{
    std::ifstream s("students.txt"); //FILE_NAME - const string defined in Input.h
    std::string str, dummy;
    std::vector<Student> students;
    int elementCnt = 0;

    try
    {
        if (s)
        {
            std::getline(s, str); //Reading first line (dummy line)
            std::istringstream sstr(str);
            while (sstr >> dummy)
                ++elementCnt;

            std::string firstName, lastName; //The actual reading of file
            while (s >> firstName >> lastName)
            {
                std::vector<int> grades;
                for (int i = 0; i < elementCnt - 2; ++i) //Loop through all non-name entities
                {
                    int grade = 0;
                    s >> grade;
                    grades.push_back(grade);
                }
                int examGrade = grades.back(); //Reading exam grade and removing it from regular grades.
                grades.pop_back();

                students.push_back(Student(firstName, lastName, grades, examGrade));
            }

            std::sort(students.begin(), students.end(), compareByLastName); //Sorting students by their last name
            s.close();                                                      //Closing the stream after the operations
        }
        else
            throw std::runtime_error(std::string("The file students.txt wasn't found... Redirecting to input by hand.."));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        students = readStudents();
    }

    return students;
}