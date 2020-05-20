#include "../headers/ContainerTests.h"
#include "../headers/Utility.h"
#include "../headers/Output.h"
#include "../headers/Input.h"
#include "../headers/Student.h"
#include "../headers/vector.h"

#include <vector>
#include <deque>
#include <list>
#include <chrono>
#include <algorithm>

//Test case
//! Vector test case
void testVector(bool sort, const std::vector<int> config)
{
    const int GENERATION_START = config[0], GENERATION_OFFSET = config[1];
    const int FILE_AMOUNT = config[2], GRADE_COUNT = config[3];
    int GENERATION_AMOUNT = GENERATION_START;

    for (int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::vector<Student> students, weakStudents, goodStudents;
        std::cout << "Using vectors for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students"
                  << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT, GRADE_COUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time for generation "
                  << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students = readStudentsFromFile<std::vector<Student>>(
            "students" + std::to_string(GENERATION_AMOUNT) + ".txt",
            false);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for reading "
                  << elapsed_seconds.count() << " s" << std::endl;
        if (!sort)
        {
            start = std::chrono::system_clock::now();
            seperateContainer1(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating using 1st method "
                      << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();
            goodStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer2(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating using 2nd method "
                      << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating using 3rd method "
                      << elapsed_seconds.count() << " s" << std::endl;
        }
        else if (sort)
        {
            start = std::chrono::system_clock::now();
            std::sort(students.begin(), students.end(), compareByFinalGrade);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for sorting by grade "
                      << elapsed_seconds.count() << " s" << std::endl;

            start = std::chrono::system_clock::now();
            seperateSortedContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating sorted vectors "
                      << elapsed_seconds.count() << " s" << std::endl;
        }

        start = std::chrono::system_clock::now();
        std::ofstream f1("smartStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        std::ofstream f2("lameStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        printStudentInfo(students, f1);
        printStudentInfo(weakStudents, f2);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for printing out the seperated results "
                  << elapsed_seconds.count() << " s" << std::endl;

        f1.close();
        f2.close();

        GENERATION_AMOUNT *= GENERATION_OFFSET;

        auto programStop = std::chrono::system_clock::now();
        elapsed_seconds = programStop - programStart;
        std::cout << "Total elapsed time for printing out the seperated results "
                  << elapsed_seconds.count() << " s" << std::endl;
        std::cout << "\n\n"
                  << std::endl;
    }
}

//! Deque test case
void testDeque(bool sort, const std::vector<int> config)
{
    const int GENERATION_START = config[0], GENERATION_OFFSET = config[1];
    const int FILE_AMOUNT = config[2], GRADE_COUNT = config[3];
    int GENERATION_AMOUNT = GENERATION_START;

    for (int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::deque<Student> students, weakStudents, goodStudents;
        std::cout << "Using deque for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students"
                  << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT, GRADE_COUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time for generation "
                  << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students = readStudentsFromFile<std::deque<Student>>(
            "students" + std::to_string(GENERATION_AMOUNT) + ".txt",
            false);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for reading "
                  << elapsed_seconds.count() << " s" << std::endl;

        if (sort)
        {
            start = std::chrono::system_clock::now();
            std::sort(students.begin(), students.end(), compareByFinalGrade);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for sorting by grade "
                      << elapsed_seconds.count() << " s" << std::endl;

            start = std::chrono::system_clock::now();
            seperateSortedContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating sorted deque "
                      << elapsed_seconds.count() << " s" << std::endl;
        }
        else if (!sort)
        {
            start = std::chrono::system_clock::now();
            seperateContainer1(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating deque using 1st method "
                      << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();
            goodStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer2(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating deque using 2nd method "
                      << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating deque using 3rd method "
                      << elapsed_seconds.count() << " s" << std::endl;
        }

        start = std::chrono::system_clock::now();
        std::ofstream f1("smartStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        std::ofstream f2("lameStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        printStudentInfo(students, f1);
        printStudentInfo(weakStudents, f2);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for printing out the seperated results "
                  << elapsed_seconds.count() << " s" << std::endl;

        f1.close();
        f2.close();

        GENERATION_AMOUNT *= GENERATION_OFFSET;

        auto programStop = std::chrono::system_clock::now();
        elapsed_seconds = programStop - programStart;
        std::cout << "Total elapsed time for printing out the seperated results "
                  << elapsed_seconds.count() << " s" << std::endl;
        std::cout << "\n\n"
                  << std::endl;
    }
}

//! List test case
void testList(bool sort, const std::vector<int> config)
{
    const int GENERATION_START = config[0], GENERATION_OFFSET = config[1];
    const int FILE_AMOUNT = config[2], GRADE_COUNT = config[3];
    int GENERATION_AMOUNT = GENERATION_START;

    for (int i = 0; i < FILE_AMOUNT; ++i)
    {
        std::list<Student> students, weakStudents, goodStudents;
        std::cout << "Using lists for storing data..." << std::endl;
        std::cout << "Starting generation and analysis of students"
                  << GENERATION_AMOUNT << ".txt..." << std::endl;

        auto programStart = std::chrono::system_clock::now();
        auto start = std::chrono::system_clock::now();
        generateTestFile(GENERATION_AMOUNT, GRADE_COUNT);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Elapsed time for list generation "
                  << elapsed_seconds.count() << " s" << std::endl;

        start = std::chrono::system_clock::now();
        students = readStudentsFromFile<std::list<Student>>(
            "students" + std::to_string(GENERATION_AMOUNT) + ".txt",
            false);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for reading "
                  << elapsed_seconds.count() << " s" << std::endl;

        if (sort)
        {
            start = std::chrono::system_clock::now();
            students.sort(compareByFinalGrade);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for sorting list by grade "
                      << elapsed_seconds.count() << " s" << std::endl;

            start = std::chrono::system_clock::now();
            seperateSortedContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating sorted lists "
                      << elapsed_seconds.count() << " s" << std::endl;
        }
        else if (!sort)
        {
            start = std::chrono::system_clock::now();
            seperateContainer1(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating lists using 1st method "
                      << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();
            goodStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer2(students, weakStudents, goodStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating lists using 2nd method "
                      << elapsed_seconds.count() << " s" << std::endl;

            weakStudents.clear();

            start = std::chrono::system_clock::now();
            seperateContainer(students, weakStudents);
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Elapsed time for seperating lists using 3rd method "
                      << elapsed_seconds.count() << " s" << std::endl;
        }

        start = std::chrono::system_clock::now();
        std::ofstream f1("smartStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        std::ofstream f2("lameStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
        printStudentInfo(students, f1);
        printStudentInfo(weakStudents, f2);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Elapsed time for printing out the seperated results "
                  << elapsed_seconds.count() << " s" << std::endl;

        f1.close();
        f2.close();

        GENERATION_AMOUNT *= GENERATION_OFFSET;

        auto programStop = std::chrono::system_clock::now();
        elapsed_seconds = programStop - programStart;
        std::cout << "Total elapsed time for printing out the seperated results "
                  << elapsed_seconds.count() << " s" << std::endl;
        std::cout << "\n\n"
                  << std::endl;
    }
}

// //! Test case for rice::vector
// void testRiceVector(bool sort, const std::vector<int> config)
// {
//     const int GENERATION_START = config[0], GENERATION_OFFSET = config[1];
//     const int FILE_AMOUNT = config[2], GRADE_COUNT = config[3];
//     int GENERATION_AMOUNT = GENERATION_START;

//     for (int i = 0; i < FILE_AMOUNT; ++i)
//     {
//         rice::vector<Student> students, weakStudents, goodStudents;
//         std::cout << "Using vectors for storing data..." << std::endl;
//         std::cout << "Starting generation and analysis of students"
//                   << GENERATION_AMOUNT << ".txt..." << std::endl;

//         auto programStart = std::chrono::system_clock::now();
//         auto start = std::chrono::system_clock::now();
//         generateTestFile(GENERATION_AMOUNT, GRADE_COUNT);
//         auto end = std::chrono::system_clock::now();
//         std::chrono::duration<double> elapsed_seconds = end - start;
//         std::cout << "Elapsed time for generation "
//                   << elapsed_seconds.count() << " s" << std::endl;

//         start = std::chrono::system_clock::now();
//         students = readStudentsFromFile<rice::vector<Student>>(
//             "students" + std::to_string(GENERATION_AMOUNT) + ".txt",
//             false);
//         end = std::chrono::system_clock::now();
//         elapsed_seconds = end - start;
//         std::cout << "Elapsed time for reading "
//                   << elapsed_seconds.count() << " s" << std::endl;
//         if (!sort)
//         {
//             start = std::chrono::system_clock::now();
//             seperateContainer1(students, weakStudents, goodStudents);
//             end = std::chrono::system_clock::now();
//             elapsed_seconds = end - start;
//             std::cout << "Elapsed time for seperating using 1st method "
//                       << elapsed_seconds.count() << " s" << std::endl;

//             weakStudents.clear();
//             goodStudents.clear();

//             start = std::chrono::system_clock::now();
//             seperateContainer2(students, weakStudents, goodStudents);
//             end = std::chrono::system_clock::now();
//             elapsed_seconds = end - start;
//             std::cout << "Elapsed time for seperating using 2nd method "
//                       << elapsed_seconds.count() << " s" << std::endl;

//             weakStudents.clear();

//             start = std::chrono::system_clock::now();
//             seperateContainer(students, weakStudents);
//             end = std::chrono::system_clock::now();
//             elapsed_seconds = end - start;
//             std::cout << "Elapsed time for seperating using 3rd method "
//                       << elapsed_seconds.count() << " s" << std::endl;
//         }
//         else if (sort)
//         {
//             start = std::chrono::system_clock::now();
//             std::sort(students.begin(), students.end(), compareByFinalGrade);
//             end = std::chrono::system_clock::now();
//             elapsed_seconds = end - start;
//             std::cout << "Elapsed time for sorting by grade "
//                       << elapsed_seconds.count() << " s" << std::endl;

//             start = std::chrono::system_clock::now();
//             seperateSortedContainer(students, weakStudents);
//             end = std::chrono::system_clock::now();
//             elapsed_seconds = end - start;
//             std::cout << "Elapsed time for seperating sorted vectors "
//                       << elapsed_seconds.count() << " s" << std::endl;
//         }

//         start = std::chrono::system_clock::now();
//         std::ofstream f1("smartStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
//         std::ofstream f2("lameStudents" + std::to_string(GENERATION_AMOUNT) + ".txt");
//         printStudentInfo(students, f1);
//         printStudentInfo(weakStudents, f2);
//         end = std::chrono::system_clock::now();
//         elapsed_seconds = end - start;
//         std::cout << "Elapsed time for printing out the seperated results "
//                   << elapsed_seconds.count() << " s" << std::endl;

//         f1.close();
//         f2.close();

//         GENERATION_AMOUNT *= GENERATION_OFFSET;

//         auto programStop = std::chrono::system_clock::now();
//         elapsed_seconds = programStop - programStart;
//         std::cout << "Total elapsed time for printing out the seperated results "
//                   << elapsed_seconds.count() << " s" << std::endl;
//         std::cout << "\n\n"
//                   << std::endl;
//     }
// }