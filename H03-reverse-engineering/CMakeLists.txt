# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H03-reverse-engineering
project (H03-reverse-engineering)

# Create an executable named 'reverse-engineering' from the source file 'reverse-engineering.cxx'
add_executable(reverse-engineering src/reverse-engineering.cxx)

# Create an additional target for assignment submission
add_assignment(reverse-engineering src/reverse-engineering.cxx)
