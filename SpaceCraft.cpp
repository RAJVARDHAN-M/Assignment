#include <iostream>
#include <vector>
#include "Assignments.cpp"

// Function to simulate spacecraft movement and return the final position and direction
std::pair<SpacePoint, Direction> simulateSpacecraftMovement(int startX, int startY, int startZ, Direction initialDirection, const std::vector<char>& commands) {
    Spacecraft spacecraft(startX, startY, startZ, initialDirection);
    for (char command : commands) {
        spacecraft.move(command);
    }
    return std::make_pair(spacecraft.getCurrentPosition(), spacecraft.getCurrentDirection());
}

// Function to run tests
void runTests() {
    // Test case 1: Initial position and direction
    {
        std::vector<char> commands;
        int startX = 0, startY = 0, startZ = 0;
        Direction initialDirection = N;
        auto result = simulateSpacecraftMovement(startX, startY, startZ, initialDirection, commands);
        assert(result.first.xPos == 0);
        assert(result.first.yPos == 0);
        assert(result.first.zPos == 0);
        assert(result.second == Direction::N);
        std::cout << "Initial Position and Direction Test: Passed\n";
    }

    // Test case 2: Moving forward
    {
        std::vector<char> commands = {'f'};
        int startX = 0, startY = 0, startZ = 0;
        Direction initialDirection = N;
        auto result = simulateSpacecraftMovement(startX, startY, startZ, initialDirection, commands);
        assert(result.first.xPos == 0);
        assert(result.first.yPos == 1);
        assert(result.first.zPos == 0);
        assert(result.second == Direction::N);
        std::cout << "Move Forward Test: Passed\n";
    }

    // Add more test cases here...

    std::cout << "All tests passed!\n";
}

int main() {
    // Run tests
    runTests();

    // Interactive code for spacecraft movement
    int startX = 0, startY = 0, startZ = 0;
    Direction initialDirection = N;
    std::vector<char> commands;
    char input;
    std::cout << "Enter a sequence of commands (f, b, l, r, u, d), one character at a time. Enter 'q' to finish: " << std::endl;
    while (std::cin >> input && input != 'q') {
        commands.push_back(input);
    }

    // Simulate spacecraft movement
    auto result = simulateSpacecraftMovement(startX, startY, startZ, initialDirection, commands);

    // Output final position and direction
    std::cout << "Final Position: (" << result.first.xPos << ", " << result.first.yPos << ", " << result.first.zPos << ")\n";
    std::cout << "Final Direction: " << result.second << "\n";

    return 0;
}
