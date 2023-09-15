# C++ Spacecraft Simulation Project

This C++ project simulates the movement of a 3D spacecraft using the `Spacecraft` class. The spacecraft can move forward, backward, rotate left, rotate right, rotate upward, and rotate downward. The project also includes test cases to ensure the correctness of the spacecraft's movement.

## Table of Contents

- [Project Structure](#project-structure)
- [How to Compile and Run](#how-to-compile-and-run)
- [Usage](#usage)
- [Testing](#testing)

## Project Structure

The project consists of the following files:

- `Assignments.cpp`: Contains the `SpacePoint` structure and the `Spacecraft` class definition.
- `SpaceCraft.cpp`: Defines a function to simulate spacecraft movement and includes a `runTests` function for testing.
- `testcase.cpp`: Contains individual test functions to verify the functionality of the `Spacecraft` class.

## How to Compile and Run

To compile and run the project, follow these steps:

1. Ensure you have a C++ compiler (e.g., g++) installed on your system.

2. Open a terminal or command prompt.

3. Navigate to the project directory containing all the source files.

4. Compile the code using the following commands:

   ```bash
   g++ -o Assignments Assignments.cpp
   g++ -o SpaceCraft SpaceCraft.cpp
   g++ -o testcase testcase.cpp
