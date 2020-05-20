#include "../headers/ContainerTests.h"

#include <gtest/gtest.h>
#include <iostream>

//! Numer of Students to start generating from
const int GENERATION_START = 1000;
//! Generation offset
const int GENERATION_OFFSET = 10;
//! File amount declaration
const int FILE_AMOUNT = 5;
//! Grade count for each Student generated
const int GRADE_COUNT = 15;

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
        std::cout << "Specify test container type: v for vector, d for deque,"
                  << " l for list, a for all" << std::endl;
        std::cout << "\nIf you want to run gtest, use t" << std::endl;

        return -1;
    }
    else
    {
        const std::vector<int> config = { GENERATION_START, GENERATION_OFFSET, FILE_AMOUNT, GRADE_COUNT };

        if (tolower(*argv[1]) == 'v')
            testVector(sort, config);
        else if (tolower(*argv[1]) == 'd')
            testDeque(sort, config);
        else if (tolower(*argv[1]) == 'l')
            testList(sort, config);
        // else if (tolower(*argv[1]) == 'r')
        //     testRiceVector(sort, config);
        else if (tolower(*argv[1]) == 'a')
        {
            testVector(sort, config);
            testDeque(sort, config);
            testList(sort, config);
            //testRiceVector(sort, config);
        }
        else if (tolower(*argv[1]) == 't')
        {
            testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }
        else
        {
            std::cout << "Specify test container type: v for vector,"
                      << " d for deque, l for list" << std::endl;
            std::cout << "\nIf you want to run gtest, use t" << std::endl;

            return -1;
        }
    }
    std::cout << "End of test..." << std::endl;

    return 0;
}