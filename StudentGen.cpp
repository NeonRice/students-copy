#include "headers/Input.h"
#include <chrono>

const int GENERATION_START = 1000;
const int GENERATION_OFFSET = 10;
const int FILE_AMOUNT = 5;

void generateTestFile(int GENERATION_AMOUNT)
{
        int gradeCount = rand() % MAX_GRADES + 1;

        //Generating labels
        std::ofstream file("students" + std::to_string(GENERATION_AMOUNT) + ".txt");
        file << std::left << std::setw(18) << "Vardas" << std::setw(18) << "Pavarde";
        for(int i = 1; i <= gradeCount; ++i)
            file << std::left <<  "ND" << std::setw(10) << i;
        file << "Egz." << std::endl;

        for(int i = 1; i <= GENERATION_AMOUNT; ++i)
        {
            file << std::left  << "Vardas" << std::setw(12) << i << "Pavarde" << std::setw(12) << i;
            for(int i = 0; i <= gradeCount; ++i)
                file << std::setw(12) << rand() % 10 + 1;
            file << std::endl;
        }
}

inline bool compareByFinalGrade(Student &a, Student &b) //Comparison function
{
    return a.getAverage() > b.getAverage();
}

void seperateVector(std::vector<Student> &students, std::vector<Student> &weakStudents) // Vector must be sorted in decreasing grade order in order for the function to work correctly
{
    auto it = students.begin(); auto b = students.begin();
    for(; it < students.end(); ++it)
    {
        if((*it).getAverage() < 5.0)
            weakStudents.push_back(*it);
        if((*it).getAverage() >= 5.0)
            b = it;
    }
    students.erase(b, it);
}

void seperateVector2(std::vector<Student> &students, std::vector<Student> &weakStudents, std::vector<Student> &newStudents) // Vector must be sorted in decreasing grade order in order for the function to work correctly
{
    auto it = students.begin();
    for(; it < students.end(); ++it)
    {
        if((*it).getAverage() < 5.0)
            weakStudents.push_back(*it);
        if((*it).getAverage() >= 5.0)
            newStudents.push_back(*it);
    }
    students.clear();
}

int main()
{
    int GENERATION_AMOUNT = GENERATION_START;
    for(int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::vector<Student> students, weakStudents;
        std::cout << "Starting generation and analysis of students" << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time for generation " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students = readStudentsFromFile("students" + std::to_string(GENERATION_AMOUNT) + ".txt");
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        std::cout << "Elapsed time for reading " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        std::sort(students.begin(), students.end(), compareByFinalGrade);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        std::cout << "Elapsed time for sorting by grade " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        seperateVector(students, weakStudents);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        std::cout << "Elapsed time for seperating vectors " << elapsed_seconds.count() << " s" << std::endl;



        start = std::chrono::system_clock::now();
        std::ofstream f1("smartStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        std::ofstream f2("lameStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        printStudentInfo(students, f1);
        printStudentInfo(weakStudents, f2);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        std::cout << "Elapsed time for printing out the seperated results " << elapsed_seconds.count() << " s" << std::endl;

        f1.close();
        f2.close();

        GENERATION_AMOUNT *= GENERATION_OFFSET;

        auto programStop = std::chrono::system_clock::now();
        elapsed_seconds = programStop - programStart;
        std::cout << "Total elapsed time for printing out the seperated results " << elapsed_seconds.count() << " s" << std::endl;
        std::cout << "\n\n" << std::endl;

    }
    std::cout << "End of test..." << std::endl;
    
    return 0;
}