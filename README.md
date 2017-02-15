# WI4771TU
This Git repository contains course material, examples and assignments
for the course "Object Oriented Scientific Programming with C++"
(wi4771tu) given in the Faculty of Electrical Engineering, Applied
Mathematics and Computer Sciences at Delft University of Technology in
the third quarter of the academic year 2016/2017 by Matthias Moller.

This git repository is maintained at [gitlab wi4771tu].

## Lecture schedule
-   The lectures will be given on **Tuesdays between 10:45 and 12:45** 
    in the indicated lecture halls. 
-   The **lab sessions** take place on **Fridays between 13:45 and 17:45** 
    in the **Computer room 1** in the exam building Drebbelweg (DW-PC1 on the 1st floor).

[Week 1](slides/week1.pdf) CT-Collegezaal E
-  Introduction to git and cmake;
-  Constants, variables, and scope;
-  Dynamic memory allocation
-  **Examples:**
   [01-hello],
   [02-variables-constants],
   [03-pointers],
   [04-passing-arguments], and
   [05-namespaces]
- **Homework:**
   [H01-swap],
   [H02-arrays], and
   [H03-reverse-engineering].

[Week 2](slides/week2.pdf) IO-Bernd Schierbeek
- Functions;
- Pointers, arrays, and references;
- Lvalues, rvalues and their references;
- Copy and move semantics (especially in C++11)
   
[Week 3](slides/week3.pdf) CT-Collegezaal B
- Introduction to object-oriented programming;
- Namespaces, structures and classes
   
[Week 4](slides/week4.pdf) CT-Collegezaal C
- Introduction to template meta programming;
- Parameterized types;
- Advanced class hierarchies (abstract classes, virtual functions);
- Static vs. dynamic polymorphism
   
[Week 5](slides/week5.pdf) CT-Collegezaal E
- Partial class spezialization, traits;
- Variadic templates;
- Functors (=function objects)
   
[Week 6](slides/week6.pdf) CT-Collegezaal C
- Introduction of the standard template library (STL);
- Containers (array, vector, list);
- Iterators;
- I/O streams;
- Exception handling
   
[Week 7](slides/week7.pdf) CT-Collegezaal F
- Basic introduction to expression templates
- Overview of the Blaze or VexCL library

## Prerequisites
The PCs in the computer room DW-PC1 running under SUSE Linux Enterprise Desktop 
12 SP1 are equipped with all software necessary for this course. If you prefer 
using your private laptop please make sure that you have installed all necessary
software. **Please note that we cannot give any kind of support for installing
software on private laptops. In this case you are on your own.**

### Git
The version control system Git is available by the `git` command. If you work on
your own PC please install Git as explained on the website https://git-scm.com.

### CMake
The build system CMake is available by the `cmake` command. If you work on
your own PC please install CMake (version 3.1 or better) as explained on the
website https://cmake.org.

### C++ compiler
The GNU C++ Compiler 5.1 is available by the `g++` command. If you work on
your own PC please install a C++ compiler that has full C++11 support. Compilers
that are known to work are GNU C++ 5.x or 6.x (https://gcc.gnu.org), Xcode on 
macOS (available via the AppStore), and Microsoft Visual Studio Community Edition
(available for free via https://www.visualstudio.com/downloads/).


## Getting started

1. Fetch the repository
   ```
   git clone https://gitlab.com/mmoelle1/wi4771tu.2017
   ```
   or use a Git GUI under Windows to obtain the lecture slides, example programs
   and homework assignments.
   
2. On the PCs in DW-PC1 load the necessary compilers by running
   ```
   source $HOME/wi4771tu.2017/tudelft.bashrc
   ```
   In order to execute this command each time you login to the PC run
   ```
   echo "source $HOME/wi4771tu.2017/tudelft.bashrc" >> .bashrc
   ```
   
3. Create a `build` directory and run CMake
   ```
   cd wi4771tu.2017
   mkdir build
   cd build
   cmake ..
   ```
   This will generate all required Makefiles needed to compile the examples.
   
   If you work on your private laptop and have different compilers installed it
   might be necessary to specify the one you intend to use explicitly by running
   ```
   CC=gcc-5 CXX=g++-5 cmake ..
   ```
   
   On Windows, the CMake GUI will detect installed C++ compilers automatically 
   and suggest possible targets. The easiest way is to generate a Visual Studio
   Project which can be directly loaded into the Microsoft IDE.
   
   On macOS, CMake can generate project files that can be loaded into Xcode
   ```
   cmake -G Xcode ..
   ```
   
4. Compile the examples
   ```
   make
   ```

   If you work on Windows with Microsoft Visual Studio or macOS with Xcode open
   the project file and compile the examples from within the IDE.


[gitlab wi4771tu]: https://gitlab.com/mmoelle1/wi4771tu.2017.git

[01-hello]: 01-hello/
[02-variables-constants]: 02-variables-constants/
[03-pointers]: 03-pointers/
[04-passing-arguments]: 04-passing-arguments/
[05-namespaces]: 05-namespaces/
[06-dot-product]: 06-dot-product/
[07-dot-product-struct]: 07-dot-product-struct/
[08-dot-product-struct2]: 08-dot-product-struct2/
[09-copy-move]: 09-copy-move/
[10-integration]: 10-integration/
[11-polymorphism]: 11-polymorphism/
[12-auto-decltype]: 12-auto-decltype/
[13-templates]: 13-templates/
[14-templates-partial-specialisation]: 14-templates-partial-specialisation/
[15-traits]: 15-traits/
[16-templates-sfinae]: 16-templates-sfinae/
[17-templates-sfinae2]: 17-templates-sfinae2/
[18-complex-conjugate]: 18-complex-conjugate/
[19-templates-variadic]: 19-templates-variadic/
[20-containers]: 20-containers/
[21-algorithm]: 21-algorithm/
[22-stack-queue]: 22-stack-queue/

[H01-swap]: H01-swap/
[H02-arrays]: H02-arrays/
[H03-reverse-engineering]: H03-reverse-engineering/
[H04-points-triangles]: H04-points-triangles/
[H05-copy-move]: H05-copy-move/
[H06-derivatives]: H06-derivatives/
[H07-templates]: H07-templates/
[H08-unit-converter]: H08-unit-converter/
[H09-symbolic-differentiation]: H09-symbolic-differentiation/
[H10-add-vectors]: H10-add-vectors/

