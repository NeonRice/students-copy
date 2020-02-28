#include "headers/Input.h"
#include "headers/Student.h"


int main()
{
    std::vector<Student> students;
    bool readFromFile = yesOrNo("Read from file students.txt? (Y OR N): ");
    if(readFromFile)
        students = readStudentsFromFile();
    else
        students = readStudents();
    
    bool outputToFile = yesOrNo("Output to file studentsOutput.txt? (Y OR N): ");
    if(outputToFile)
        printStudentInfoToFile(students);
    else
        printStudentInfo(students);

}
