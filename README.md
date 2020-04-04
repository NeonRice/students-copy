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
<br />2.1 If you chose the grades to be generated randomly, you will input the student names.
<br />2.2 If you chose the grades to NOT be generated randomly, you will input the student names, following their grades and exam grade.
3. Choose if you want to output to file or terminal.


## Releases
 [v0.1](https://github.com/NeonRice/students/releases/tag/v0.1) 
 <br />[v0.2](https://github.com/NeonRice/students/releases/tag/v0.2)
 <br />[v0.3](https://github.com/NeonRice/students/releases/tag/v0.3)
 <br />[v0.4](https://github.com/NeonRice/students/releases/tag/v0.4)
 <br />[v0.5](https://github.com/NeonRice/students/releases/tag/v0.5)
 <br />[v1.0](https://github.com/NeonRice/students/releases/tag/v1.0)

  
