#include "headers/Input.h"
#include "headers/Student.h"

const std::string OUT_FILE_NAME = "studentsOutput.txt";

int main()
{
    Student s("Zanas", "Kovaliovas");
    Student temp = s;
    std::cout << temp.getFirstName() << std::endl;
    std::vector<Student> students;
    bool readFromFile = yesOrNo("Read from file students.txt? (Y OR N): ");
    if (readFromFile)
        students = readStudentsFromFile();
    else
        students = readStudents();

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
