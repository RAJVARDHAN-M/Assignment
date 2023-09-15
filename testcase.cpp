#include <iostream>
#include <cassert>
#include "Assignments.cpp" // Include the Spacecraft class from Assignments.cpp

// Function to test the initial position and direction of the spacecraft
void testInitialPosition()
{
    Spacecraft spacecraft(0, 0, 0, Direction::North); // Create a spacecraft object at (0, 0, 0) facing North

    // Check if the initial position and direction are as expected
    assert(spacecraft.getX() == 0);
    assert(spacecraft.getY() == 0);
    assert(spacecraft.getZ() == 0);
    assert(spacecraft.getDirection() == Direction::North);

    std::cout << "Initial Position Test: Passed\n";
}

// Function to test moving the spacecraft forward
void testmvfd()
{
    Spacecraft spacecraft(0, 0, 0, Direction::North); // Create a spacecraft object at (0, 0, 0) facing North
    spacecraft.executeCommands({'f'}); // Execute a 'f' (forward) command

    // Check if the spacecraft's position and direction have changed correctly
    assert(spacecraft.getX() == 0);
    assert(spacecraft.getY() == 1);
    assert(spacecraft.getZ() == 0);
    assert(spacecraft.getDirection() == Direction::North);

    std::cout << "Move Forward Test: Passed\n";
}

// Function to test moving the spacecraft backward
void testmvBd()
{
    Spacecraft spacecraft(0, 0, 0, Direction::North); // Create a spacecraft object at (0, 0, 0) facing North
    spacecraft.executeCommands({'b'}); // Execute a 'b' (backward) command

    // Check if the spacecraft's position and direction have changed correctly
    assert(spacecraft.getX() == 0);
    assert(spacecraft.getY() == -1);
    assert(spacecraft.getZ() == 0);
    assert(spacecraft.getDirection() == Direction::North);

    std::cout << "Move Backward Test: Passed\n";
}

// Function to test turning the spacecraft left
void testTl()
{
    Spacecraft spacecraft(0, 0, 0, Direction::North); // Create a spacecraft object at (0, 0, 0) facing North
    spacecraft.executeCommands({'l'}); // Execute an 'l' (left) command

    // Check if the spacecraft's direction has changed correctly
    assert(spacecraft.getDirection() == Direction::West);

    std::cout << "Turn Left Test: Passed\n";
}

// Function to test turning the spacecraft right
void testTr()
{
    Spacecraft spacecraft(0, 0, 0, Direction::North); // Create a spacecraft object at (0, 0, 0) facing North
    spacecraft.executeCommands({'r'}); // Execute an 'r' (right) command

    // Check if the spacecraft's direction has changed correctly
    assert(spacecraft.getDirection() == Direction::East);

    std::cout << "Turn Right Test: Passed\n";
}

// Function to test turning the spacecraft upward
void testTu()
{
    Spacecraft spacecraft(0, 0, 0, Direction::North); // Create a spacecraft object at (0, 0, 0) facing North
    spacecraft.executeCommands({'u'}); // Execute a 'u' (upward) command

    // Check if the spacecraft's direction has changed correctly
    assert(spacecraft.getDirection() == Direction::Up);

    std::cout << "Turn Up Test: Passed\n";
}

// Function to test turning the spacecraft downward
void testTd()
{
    Spacecraft spacecraft(0, 0, 0, Direction::North); // Create a spacecraft object at (0, 0, 0) facing North
    spacecraft.executeCommands({'d'}); // Execute a 'd' (downward) command

    // Check if the spacecraft's direction has changed correctly
    assert(spacecraft.getDirection() == Direction::Down);

    std::cout << "Turn Down Test: Passed\n";
}

int main()
{
    // Run the individual test functions
    testInitialPosition();
    testmvfd();
    testmvBd();
    testTl();
    testTr();
    testTu();
    testTd();

    // Additional test cases:

    // Test moving forward twice
    Spacecraft spacecraft2(0, 0, 0, Direction::North);
    spacecraft2.executeCommands({'f', 'f'});
    assert(spacecraft2.getY() == 2);

    // Test turning right twice
    Spacecraft spacecraft3(0, 0, 0, Direction::North);
    spacecraft3.executeCommands({'r', 'r'});
    assert(spacecraft3.getDirection() == Direction::South);

    // Test moving forward, turning left, and moving forward again
    Spacecraft spacecraft4(0, 0, 0, Direction::North);
    spacecraft4.executeCommands({'f', 'l', 'f'});
    assert(spacecraft4.getX() == -1);
    assert(spacecraft4.getDirection() == Direction::West);

    std::cout << "All tests passed!\n";

    return 0;
}
