#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <random>

const int MAX_GRADES = 100;

class Student
{   
    private:
        std::string firstName, lastName = "";
        double examGrade = 0;
        std::vector<int> grades;

    public:
        Student() {}
        Student(std::string fN, std::string lN):firstName(fN), lastName(lN) {}
        Student(double eX, std::vector<int> g):examGrade(eX), grades(g){}
        Student(std::string fN, std::string lN, std::vector<int> g)
        :firstName(fN), lastName(lN), grades(g) {}

        std::string getFirstName() const {return firstName;}
        std::string getLastName() const {return lastName;}


        friend void printStudentInfo(Student s);

        void readStudentName()  //Read the first and last names with validity checks
        {
            std::string first = "", last = "";
            std::size_t ch;
            do
            {
                std::cout << "Enter full student name: ";
                std::cin >> first >> last;
                std::string fullName = first + last;
                ch = fullName.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
            } while (ch != std::string::npos);
            firstName = first; lastName = last;
        }

        void readStudentGrades()    //Reads students grades with validity checks, input stops when X inputted
        {
            std::cout << "Enter student grades:" << std::endl;
            std::string b;   
            while(std::cin >> b && b != "x" && b != "X")
            {
                int c;
                try
                {
                    c = std::stoi(b);
                }
                catch(const std::exception& e)
                {
                    std::cout << "Invalid argument skipped. Insert only ints" << std::endl;
                    continue;
                }
                if(c < 0 || c > 10)
                    continue;
                grades.push_back(c);
            }
        }

        void readExamGrade()    //Reads exam grade (the 1st one entered if entered more)
        {
            std::string b;
            int c;
            std::cout << "Enter student exam grade: ";
            while(std::cin >> b)
            {
                try
                {
                    c = std::stoi(b);
                }
                catch(const std::exception& e)
                {
                    continue;
                }
                if(c < 0 || c > 10)
                    continue;
                break;
            }
            examGrade = c;
        }

        double getAverage() //Returns the average of grades using the given formula
        {
            double gradeSum = 0;
            for (size_t i = 0; i < grades.size(); i++)
            {
                gradeSum += grades[i];
            }
            return (double) (gradeSum / grades.size()) * 0.4 + 0.6 * (double) examGrade;
        }

        double getMedian()  //Return the median of grades
        {
            std::sort(grades.begin(), grades.end());
            if (grades.size() % 2)
            {
                return ((double)grades[grades.size() / 2] + grades[(grades.size() / 2) - 1]) / 2;
            }
            else
            {
                return grades[grades.size() / 2];
            }
        }
};

void printStudentInfo(std::vector<Student> s)   //Trial of formatted output, currently not working completely correctly 
{
    std::cout << "Last Name" << std::setw(16) << "First Name" << std::setw(12) << "Average" << std::setw(12) << "Median" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    for (size_t i = 0; i < s.size(); i++)
    {
        std::cout << s[i].getLastName() << std::setw(12) << s[i].getFirstName() << std::setw(12) 
        << std::setprecision(3) << s[i].getAverage() << std::setw(12) << s[i].getMedian() << std::endl;
    }
}

std::vector<Student> readStudents() //Basically all the start-input logic is handled in this function
{
    int studNum = 0;
    std::vector<Student> students;
    std::cout << "How many students do you want to input?: ";
    std::cin >> studNum;
    while(1)
    {
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<< "Wrong input! Try again." << std::endl;
            std::cin >> studNum;
        }
        if(!std::cin.fail())
            break;
    }
    std::cout << "Generate random grades and exam score? (Y OR N): " << std::endl;
    char choice;
    while(1){
        std::cin >> choice;
        if(choice == 'Y' || choice == 'y')
        {
            for (size_t i = 0; i < studNum; i++)
            {
                std::vector<int> grades;
                int examGrade = rand() % 10 + 1;
                int gradeNum = rand() % MAX_GRADES + 1;
                for(int i = 0; i < gradeNum; ++i)
                    grades.push_back(rand() % 10 + 1);
                Student s(examGrade, grades);
                s.readStudentName();
                students.push_back(s);
            }
            break;
        }
        else if(choice == 'N' || choice == 'n'){
            for (size_t i = 0; i < studNum; i++)
            {
                Student s;
                s.readStudentName();
                s.readStudentGrades();
                s.readExamGrade();
                students.push_back(s);
            }
            break;
        }
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input! Try again!" << std::endl;
        }
    }

    return students;
}


int main()
{
    Student s;
    std::vector<Student> students = readStudents();
    Student a = students[0];
    printStudentInfo(students);
}
