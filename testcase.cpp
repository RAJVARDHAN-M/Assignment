#include <iostream>
#include <cassert>
#include "Assignments.cpp"

void testInitialPosition()
{
    Spacecraft spacecraft(0, 0, 0, Direction::N);

    assert(spacecraft.getX() == 0);
    assert(spacecraft.getY() == 0);
    assert(spacecraft.getZ() == 0);
    assert(spacecraft.getDirection() == Direction::N);

    std::cout << "Initial Position Test: Passed\n";
}

void testMoveForward()
{
    Spacecraft spacecraft(0, 0, 0, Direction::N);
    spacecraft.move('f');

    assert(spacecraft.getX() == 0);
    assert(spacecraft.getY() == 1);
    assert(spacecraft.getZ() == 0);
    assert(spacecraft.getDirection() == Direction::N);

    std::cout << "Move Forward Test: Passed\n";
}

void testMoveBackward()
{
    Spacecraft spacecraft(0, 0, 0, Direction::N);
    spacecraft.move('b');

    assert(spacecraft.getX() == 0);
    assert(spacecraft.getY() == -1);
    assert(spacecraft.getZ() == 0);
    assert(spacecraft.getDirection() == Direction::N);

    std::cout << "Move Backward Test: Passed\n";
}

void testTurnLeft()
{
    Spacecraft spacecraft(0, 0, 0, Direction::N);
    spacecraft.move('l');

    assert(spacecraft.getDirection() == Direction::W);

    std::cout << "Turn Left Test: Passed\n";
}

void testTurnRight()
{
    Spacecraft spacecraft(0, 0, 0, Direction::N);
    spacecraft.move('r');

    assert(spacecraft.getDirection() == Direction::E);

    std::cout << "Turn Right Test: Passed\n";
}

void testTurnUp()
{
    Spacecraft spacecraft(0, 0, 0, Direction::N);
    spacecraft.move('u');

    assert(spacecraft.getDirection() == Direction::Up);

    std::cout << "Turn Up Test: Passed\n";
}

void testTurnDown()
{
    Spacecraft spacecraft(0, 0, 0, Direction::N);
    spacecraft.move('d');

    assert(spacecraft.getDirection() == Direction::Down);

    std::cout << "Turn Down Test: Passed\n";
}

int main()
{
    testInitialPosition();
    testMoveForward();
    testMoveBackward();
    testTurnLeft();
    testTurnRight();
    testTurnUp();
    testTurnDown();

    // Additional test cases:
    
    // Test moving forward twice
    Spacecraft spacecraft2(0, 0, 0, Direction::N);
    spacecraft2.move('f');
    spacecraft2.move('f');
    assert(spacecraft2.getY() == 2);

    // Test turning right twice
    Spacecraft spacecraft3(0, 0, 0, Direction::N);
    spacecraft3.move('r');
    spacecraft3.move('r');
    assert(spacecraft3.getDirection() == Direction::S);

    // Test moving forward, turning left, and moving forward again
    Spacecraft spacecraft4(0, 0, 0, Direction::N);
    spacecraft4.move('f');
    spacecraft4.move('l');
    spacecraft4.move('f');
    assert(spacecraft4.getX() == -1);
    assert(spacecraft4.getDirection() == Direction::W);

    std::cout << "All tests passed!\n";

    return 0;
}
