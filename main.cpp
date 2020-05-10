#include "headers/Input.h"
#include "headers/Output.h"
#include "headers/Student.h"

const std::string OUT_FILE_NAME = "studentsOutput.txt";

int main()
{
    std::vector<Student> students;
    
    bool readFromFile = yesOrNo("Read from file students.txt? (Y OR N): ");
    if (readFromFile)
        students = readStudentsFromFile<std::vector<Student>>();
    else
        students = readStudents<std::vector<Student>>();

    bool outputToFile = yesOrNo("Output to file studentsOutput.txt? (Y OR N): ");
    if (outputToFile)
    {
        std::ofstream out(OUT_FILE_NAME);
        printStudentInfo(students, out);
        out.close();
    }
    else
        printStudentInfo(students, std::cout);

    return 0;
}
