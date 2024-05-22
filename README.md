# social-therapy

## Welcome to our application!

This applicaion a social medium that can be used as a personal journal or a blog with friends!
At the user's discretion, we also plan to implement an AI that will analyze the user's journal to give detailed analysis about the user's emotions and thoughts.

By no means is this professional or medical software. This is simply a project for fun and practicing with AI.

## Building the Program
1. Create a build directory and change the current working directory to it:
```bash
mkdir build && cd build
```
2. Run CMake and point it to the project directory (where the CMakeLists.txt file is located):
```bash
cmake ..
```
3. Finally, build the project:
```bash
make
```
This will run the Makefile and compile the source code to create the executable _Social_Therapy_.

## Program Execution
To run the program, simply enter
```bash
./Social_Therapy credentials.dat
```
where _credentials.bat_ is the text file that contains the usernames and passwords for each user. This file is read by the Social_Therapy program and _must_ be an argument for its execution.
