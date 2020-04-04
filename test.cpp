#include "headers/Input.h"
#include "headers/Output.h"
#include <chrono>
#include <deque>
#include <list>
#include <algorithm>

const int GENERATION_START = 1000;
const int GENERATION_OFFSET = 10;
const int FILE_AMOUNT = 5;
const int GRADE_COUNT = 15;

// Comparison inline functions

inline bool compareByFinalGrade(Student &a, Student &b) //Comparison Utility function
{
    return a.getAverage() > b.getAverage();
}

//A comparison function here for strong and weak students

inline bool IsWeakStudent(Student &s) { return ((s.getAverage() < 5.0) == 0); }
inline bool IsStrongStudent(Student &s) { return ((s.getAverage() >= 5.0) == 0); }

//Container seperation algorithms

template <typename Container>
void seperateSortedContainer(Container &students, Container &weakStudents) // Vector must be sorted in decreasing grade order in order for the function to work correctly
{
    auto it = students.begin();
    auto b = students.begin();
    for (; it != students.end(); ++it)
    {
        if ((*it).getAverage() < 5.0)
            weakStudents.push_back(*it);
        if ((*it).getAverage() >= 5.0)
            b = it;
    }
    students.erase(b, it);
}

template <typename Container>
void seperateContainer1(Container &students, Container &weakStudents, Container &newStudents)
{
    std::remove_copy_if(students.begin(), students.end(), std::back_inserter(weakStudents), IsWeakStudent);
    std::remove_copy_if(students.begin(), students.end(), std::back_inserter(newStudents), IsStrongStudent);
}

template <typename Container>
void seperateContainer2(Container &students, Container &weakStudents, Container &goodStudents) //Faster than seperateContainer2
{
    auto it = students.begin();
    for (; it != students.end(); ++it)
    {
        if ((*it).getAverage() < 5.0)
            weakStudents.push_back(*it);
        if ((*it).getAverage() >= 5.0)
            goodStudents.push_back(*it);
    }
}

template <typename Container>
void seperateContainer(Container &students, Container &weakStudents)
{
    std::remove_copy_if(students.begin(), students.end(), std::back_inserter(weakStudents), IsWeakStudent);
    students.erase(
        std::remove_if(students.begin(), students.end(), IsStrongStudent),
        students.end());
}

//Test case

void testVector(bool sort)
{
    int GENERATION_AMOUNT = GENERATION_START;
    for (int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::vector<Student> students, weakStudents, goodStudents;
        std::cout << "Using vectors for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students" << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT, GRADE_COUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time for generation " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students = readStudentsFromFile<std::vector<Student>>("students" + std::to_string(GENERATION_AMOUNT) + ".txt", false);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for reading " << elapsed_seconds.count() << " s" << std::endl;
        if (!sort)
        {
            start = std::chrono::system_clock::now();
            seperateContainer1(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating using 1st method " << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();
            goodStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer2(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating using 2nd method " << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating using 3rd method " << elapsed_seconds.count() << " s" << std::endl;
        }
        else if (sort)
        {
            start = std::chrono::system_clock::now();
            std::sort(students.begin(), students.end(), compareByFinalGrade);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for sorting by grade " << elapsed_seconds.count() << " s" << std::endl;

            start = std::chrono::system_clock::now();
            seperateSortedContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating sorted vectors " << elapsed_seconds.count() << " s" << std::endl;
        }

        start = std::chrono::system_clock::now();
        std::ofstream f1("smartStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        std::ofstream f2("lameStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        printStudentInfo(students, f1);
        printStudentInfo(weakStudents, f2);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for printing out the seperated results " << elapsed_seconds.count() << " s" << std::endl;

        f1.close();
        f2.close();

        GENERATION_AMOUNT *= GENERATION_OFFSET;

        auto programStop = std::chrono::system_clock::now();
        elapsed_seconds = programStop - programStart;
        std::cout << "Total elapsed time for printing out the seperated results " << elapsed_seconds.count() << " s" << std::endl;
        std::cout << "\n\n"
                  << std::endl;
    }
}

void testDeque(bool sort)
{
    int GENERATION_AMOUNT = GENERATION_START;
    for (int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::deque<Student> students, weakStudents, goodStudents;
        std::cout << "Using deque for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students" << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT, GRADE_COUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time for generation " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students = readStudentsFromFile<std::deque<Student>>("students" + std::to_string(GENERATION_AMOUNT) + ".txt", false);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for reading " << elapsed_seconds.count() << " s" << std::endl;

        if (sort)
        {
            start = std::chrono::system_clock::now();
            std::sort(students.begin(), students.end(), compareByFinalGrade);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for sorting by grade " << elapsed_seconds.count() << " s" << std::endl;

            start = std::chrono::system_clock::now();
            seperateSortedContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating sorted deque " << elapsed_seconds.count() << " s" << std::endl;
        }
        else if (!sort)
        {
            start = std::chrono::system_clock::now();
            seperateContainer1(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating deque using 1st method " << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();
            goodStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer2(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating deque using 2nd method " << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();
            
            start = std::chrono::system_clock::now();
            seperateContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating deque using 3rd method " << elapsed_seconds.count() << " s" << std::endl;
        }

        start = std::chrono::system_clock::now();
        std::ofstream f1("smartStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        std::ofstream f2("lameStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        printStudentInfo(students, f1);
        printStudentInfo(weakStudents, f2);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for printing out the seperated results " << elapsed_seconds.count() << " s" << std::endl;

        f1.close();
        f2.close();

        GENERATION_AMOUNT *= GENERATION_OFFSET;

        auto programStop = std::chrono::system_clock::now();
        elapsed_seconds = programStop - programStart;
        std::cout << "Total elapsed time for printing out the seperated results " << elapsed_seconds.count() << " s" << std::endl;
        std::cout << "\n\n"
                  << std::endl;
    }
}

void testList(bool sort)
{
    int GENERATION_AMOUNT = GENERATION_START;
    for (int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::list<Student> students, weakStudents, goodStudents;
        std::cout << "Using lists for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students" << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT, GRADE_COUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time for list generation " << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students = readStudentsFromFile<std::list<Student>>("students" + std::to_string(GENERATION_AMOUNT) + ".txt", false);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for reading " << elapsed_seconds.count() << " s" << std::endl;

        if (sort)
        {
            start = std::chrono::system_clock::now();
            students.sort(compareByFinalGrade);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for sorting list by grade " << elapsed_seconds.count() << " s" << std::endl;

            start = std::chrono::system_clock::now();
            seperateSortedContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating sorted lists " << elapsed_seconds.count() << " s" << std::endl;
        }
        else if(!sort)
        {
            start = std::chrono::system_clock::now();
            seperateContainer1(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating lists using 1st method " << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();
            goodStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer2(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating lists using 2nd method " << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();
            
            start = std::chrono::system_clock::now();
            seperateContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating lists using 3rd method " << elapsed_seconds.count() << " s" << std::endl;
        }

        start = std::chrono::system_clock::now();
        std::ofstream f1("smartStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        std::ofstream f2("lameStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        printStudentInfo(students, f1);
        printStudentInfo(weakStudents, f2);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for printing out the seperated results " << elapsed_seconds.count() << " s" << std::endl;

        f1.close();
        f2.close();

        GENERATION_AMOUNT *= GENERATION_OFFSET;

        auto programStop = std::chrono::system_clock::now();
        elapsed_seconds = programStop - programStart;
        std::cout << "Total elapsed time for printing out the seperated results " << elapsed_seconds.count() << " s" << std::endl;
        std::cout << "\n\n"
                  << std::endl;
    }
}

//Program entry point

int main(int argc, char *argv[])
{
    bool sort = false;

    if (argc == 3)
    {
        if (toupper(*argv[2]) == 'S')
        {
            sort = true;
        } //Should we sort or not??
    }

    if (argc < 2)
    {
        std::cout << "Specify test container type: v for vector, d for deque, l for list, a for all" << std::endl;
        return -1;
    }
    else
    {
        if (*argv[1] == 'v' || *argv[1] == 'V')
            testVector(sort);
        else if (*argv[1] == 'd' || *argv[1] == 'D')
            testDeque(sort);
        else if (*argv[1] == 'l' || *argv[1] == 'L')
            testList(sort);
        else if (*argv[1] == 'a' || *argv[1] == 'A')
        {
            testVector(sort);
            testDeque(sort);
            testList(sort);
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