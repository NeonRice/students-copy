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
3. Run the compiled binary file in the terminal of your choice using "./test CONTAINER_TYPE" (You must provide a container type such as v for vector, d for deque, l for List, a for all). If you want to run all of the test suites run "./test t"
4. OPTIONAL If you want to remove the created text files run "make testclean"

## Test results using different STL container types
<br />These were done on a system configured with 8GB of RAM and a modern i5 Intel processor. The data was written into a regular user HDD.

<br />One more important thing to note is that the tests were done on 15 grades and the data seperating time includes sorting the data first, which takes way more time than the seperating process itself.

![](https://i.imgur.com/eF1GYM6.png)
![](https://i.imgur.com/t3gXbmE.png)
<br />Since version v1.0, more seperating methods have been implemented, that do not depend on the container being sorted.
<br />Tests have been done to determine which method of seperation is the most practical and optimized.

<br />Here are some of the testing results visualized in a chart format:
![](https://i.imgur.com/Zx5fQJI.png)
<br />From the testing done on the vector container we can see that the fastest seperating methods include the 2nd and the 3rd.

<br />While the 2nd one is the fastest one it requires more memory, as it uses 3 containers - the original and 2 new ones. The original container remains unaltered after the procedure.

<br />The 3rd one saves memory by altering the original container (removing the elements copied to the other container).

<br />Following are the tests done with all of the containers using the 2nd and the 3rd method:
![](https://i.imgur.com/sY2JRvV.png)
![](https://i.imgur.com/cB5JC5w.png)
![](https://i.imgur.com/v34FGhs.png)

<br />From the testing results list and deque containers seem to be less affected by the removal of elements than vectors, while lists are affected the least of all three.

<br />In conclusion the differences in time of seperation are insignificant compared to the amount of memory that we save by using the 3rd method. If we were to use the 2nd method, vector is the clear winner, however using the 3rd method, the seperation time equals out with deque's, therefore the choice should be made between vector or deque for the seperation job solely.

## Outdated Instructions (For Version v0.1)

1. Compile the source name.cpp using your preffered C++ compiler. Example using GNU compiler: "g++ -o Students students.cpp"
2. Run the file in the terminal (where the file is downloaded) using ./Students
  
## Usage
1. Following the guideline choose if you want to read input from file (has to be named students.txt).
2. Choose if you want to output to file or terminal.

<b>If you chose to input the information yourself, then follow this usage path</b>
1. Following the guideline enter how many students you want to input.
2. You choose if you want the grades generated randomly (Y\N)
    1. If you chose the grades to be generated randomly, you will input the student names.
    2. If you chose the grades to NOT be generated randomly, you will input the student names, following their grades and exam grade.
3. Choose if you want to output to file or terminal.

## Optimization flags
The experiment was done to check which of the three main GCC optimisation flags "O1, O2, O3" decreases the test case execution time the most. In theory O3 should be the quickest execution-wise with increased memory usage and compile time.

The container used for the test was vector.
![](https://i.imgur.com/JDUOsV7.png)
![](https://i.imgur.com/fVumnoU.png)

The smallest file size was with O1 and O2 flags, O3 larger by a small margin, while O0 file size was almost double the size of O1 and O2. The execution time differences between the three optimization flags were of seconds, therefore O2 is probably the best choice based on it's file size and execution time.

 ## Release Overview
 <br />[**[v2.0]**](https://github.com/NeonRice/students-copy/releases/tag/v2.0) Major refactoring, Google Test framework implementation, Doxygen documentation.
 
 <br />[**[v1.5]**](https://github.com/NeonRice/students-copy/releases/tag/v1.5) Abstract Human interface for Student class

 <br />[**[v1.2]**](https://github.com/NeonRice/students-copy/releases/tag/v1.2) Rule of three, refactoring and Student class operators added.

 <br />[**[v1.1]**](https://github.com/NeonRice/students-copy/releases/tag/v1.1) Optimization with a compiler flag, refactoring.

 <br />[**[v1.0]**](https://github.com/NeonRice/students-copy/releases/tag/v1.0) Added 3 additional container seperation methods.
 
 <br />[**[v0.5]**](https://github.com/NeonRice/students-copy/releases/tag/v0.5) Deque and List added as container options to the testing program.
 
 <br />[**[v0.4]**](https://github.com/NeonRice/students-copy/releases/tag/v0.4) Test program added to measure vector container efficiency doing manipulative tasks with data.
 
 <br />[**[v0.3]**](https://github.com/NeonRice/students-copy/releases/tag/v0.3) Added exception handling
 
 <br />[**[v0.2]**](https://github.com/NeonRice/students-copy/releases/tag/v0.2) Added input from file and output sorting functionality. Program compilation is now done through a MAKEFILE.
 
 <br />[**[v0.1]**](https://github.com/NeonRice/students-copy/releases/tag/v0.1) Enter student info and grades, and get the overview of results displayed on the screen
  
