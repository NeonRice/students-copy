#include "headers/Input.h"
#include <chrono>
#include <deque>
#include <list>

const int GENERATION_START = 1000;
const int GENERATION_OFFSET = 10;
const int FILE_AMOUNT = 5;

void generateTestFile(int GENERATION_AMOUNT)
{
        int gradeCount = 15;

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

template <typename Container>
void printStudentInfoT(Container &s, std::ostream &out) //Formatted output to console
{
    out << std::left << std::setw(20) << "Last Name" << std::left << std::setw(20) << "First Name" << std::left << std::setw(8) << "Average" <<  "Median" << std::endl;
    out << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        out << std::left << std::setw(20) << (*i).getLastName() << std::left << std::setw(20) << (*i).getFirstName() <<  std::left << std::setw(8) << std::fixed << std::setprecision(2) << (*i).getAverage() << (*i).getMedian() << std::endl;
    }
}

template <typename Container>
void seperateVector(Container &students, Container &weakStudents) // Vector must be sorted in decreasing grade order in order for the function to work correctly
{
    auto it = students.begin(); auto b = students.begin();
    for(; it != students.end(); ++it)
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

template <typename Container>
void readStudentsFromFileT(std::string fileName, Container &students)
{
    std::ifstream s(fileName); //FILE_NAME - const string defined in Input.h
    std::string str, dummy;
    int elementCnt = 0;


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
            s.close();                                                      //Closing the stream after the operations
        }
        else
            throw std::runtime_error(std::string("The file students.txt wasn't found... Redirecting to input by hand.."));
}

void testVector()
{
    int GENERATION_AMOUNT = GENERATION_START;
    for(int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::vector<Student> students, weakStudents;
        std::cout << "Using vectors for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students" << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time for generation " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students = readStudentsFromFile("students" + std::to_string(GENERATION_AMOUNT) + ".txt", false);
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
}

void testDeque()
{
    int GENERATION_AMOUNT = GENERATION_START;
    for(int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::deque<Student> students, weakStudents;
        std::cout << "Using deque for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students" << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time for generation " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        readStudentsFromFileT("students" + std::to_string(GENERATION_AMOUNT) + ".txt", students);
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
        printStudentInfoT(students, f1);
        printStudentInfoT(weakStudents, f2);
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
}

void testList()
{
    int GENERATION_AMOUNT = GENERATION_START;
    for(int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::list<Student> students, weakStudents;
        std::cout << "Using lists for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students" << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time for generation " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        readStudentsFromFileT("students" + std::to_string(GENERATION_AMOUNT) + ".txt", students);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        std::cout << "Elapsed time for reading " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students.sort(compareByFinalGrade);
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
        printStudentInfoT(students, f1);
        printStudentInfoT(weakStudents, f2);
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
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Specify test container type: v for vector, d for deque, l for list, a for all" << std::endl;
        return -1;
    }
    else
    {
        if(*argv[1] == 'v' || *argv[1] == 'V')
            testVector();
        else if(*argv[1] == 'd' || *argv[1] == 'D')
            testDeque();
        else if(*argv[1] == 'l' || *argv[1] == 'L')
            testList();
        else if(*argv[1] == 'a' || *argv[1] == 'A')
        {
            testVector();
            testDeque();
            testList();
        }
        else
        {
            std::cout << "Specify test container type: v for vector, d for deque, l for list" << std::endl;
            return -1;
        }

    }
    std::cout << "End of test..." << std::endl;

    return 0;
}