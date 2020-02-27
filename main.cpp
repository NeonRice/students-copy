#include "headers/Input.h"
#include "headers/Student.h"


int main()
{
    std::vector<Student> students;
    bool readFromFile = selectInputMode();
    if(readFromFile)
        students = readStudentsFromFile();
    else
        students = readStudents();
    //printStudentInfo(students);
    printStudentInfoToFile(students);

}
