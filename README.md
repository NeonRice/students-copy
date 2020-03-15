# Students Application 
Prints given student info such as first name, last name, average of grades and a median with formatted output into the console or into a file studentOutput.txt

## Instructions

1. Download the binary file provided in the latest release.
2. Run the file in the terminal of our choice  (where the file is downloaded) using "./Students"

## Instructions 2

1. Download the source.
2. Compile the project using the MAKEFILE provided. (Using "make" in terminal in the source location).
3. Run the compiled file in the terminal of your choice (where the file is downloaded) using "./Students"

## Test running instructions

1. Download the source if you haven't already.
2. Compile the project using the MAKEFILE provided. (Using "make test")
3. Run the compiled binary file in the terminal of your choice using "./test CONTAINER_TYPE" (You must provide a container type such as v for vector, d for deque, l for List or a for all)
4. OPTIONAL If you want to remove the created text files run "make testclean"

## Test results using different STL container types
<br />These were done on a system configured with 8GB of RAM and a modern i5 Intel processor. The data was written into a regular user HDD.
<br />One more important thing to note is that the tests were done on 15 grades and the data seperating time includes sorting the data first, which takes way more time than the seperating process itself.
![Data seperating time with sorting](https://imgur.com/Adx5wrG)
![Data reading time](https://imgur.com/nRWJRZO)

## Outdated Instructions (For Version v0.1)

1. Compile the source name.cpp using your preffered C++ compiler. Example using GNU compiler: "g++ -o Students students.cpp"
2. Run the file in the terminal (where the file is downloaded) using ./Students
  
## Usage
1. Following the guideline choose if you want to read input from file (has to be named students.txt).
2. Choose if you want to output to file or terminal.

<b>If you chose to input the information yourself, then follow this usage path</b>
1. Following the guideline enter how many students you want to input.
2. You choose if you want the grades generated randomly (Y\N)
<br />2.1 If you chose the grades to be generated randomly, you will input the student names.
<br />2.2 If you chose the grades to NOT be generated randomly, you will input the student names, following their grades and exam grade.
3. Choose if you want to output to file or terminal.


## Releases
 [v0.1](https://github.com/NeonRice/students/releases/tag/v0.1) 
 <br />[v0.2](https://github.com/NeonRice/students/releases/tag/v0.2)
 <br />[v0.3](https://github.com/NeonRice/students/releases/tag/v0.3)
 <br />[v0.4](https://github.com/NeonRice/students/releases/tag/v0.4)
 <br />[v0.5](https://github.com/NeonRice/students/releases/tag/v0.5)

  
