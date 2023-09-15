#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Define a structure to represent coordinates in 3D space
struct SpacePoint {
    int xPos, yPos, zPos;
};

// Define an enumeration for cardinal directions and 3D orientation
enum Direction { North, South, East, West, Up, Down };

// Create a class to simulate a 3D spacecraft
class Spacecraft {
private:
    SpacePoint currentPosition;   // Store the current position (x, y, z)
    Direction currentOrientation; // Store the current direction or orientation

public:
    // Constructor to initialize the spacecraft's position and direction
    Spacecraft(int initialX, int initialY, int initialZ, Direction initialDirection) {
        currentPosition.xPos = initialX;
        currentPosition.yPos = initialY;
        currentPosition.zPos = initialZ;
        currentOrientation = initialDirection;
    }
     // Move forward in the current direction
    void mvFd() {
        switch (currentOrientation) {
            case North:
                currentPosition.yPos++;
                break;
            case South:
                currentPosition.yPos--;
                break;
            case East:
                currentPosition.xPos++;
                break;
            case West:
                currentPosition.xPos--;
                break;
            case Up:
                currentPosition.zPos++;
                break;
            case Down:
                currentPosition.zPos--;
                break;
        }
    }

    // Move backward in the current direction
    void mvBd() {
        switch (currentOrientation) {
            case North:
                currentPosition.yPos--;
                break;
            case South:
                currentPosition.yPos++;
                break;
            case East:
                currentPosition.xPos--;
                break;
            case West:
                currentPosition.xPos++;
                break;
            case Up:
                currentPosition.zPos--;
                break;
            case Down:
                currentPosition.zPos++;
                break;
        }
    }

    // Rotate left (change direction counterclockwise)
    void rotateLeft() {
        switch (currentOrientation) {
            case North:
                currentOrientation = West;
                break;
            case South:
                currentOrientation = East;
                break;
            case East:
                currentOrientation = North;
                break;
            case West:
                currentOrientation = South;
                break;
        }
    }

    // Rotate right (change direction clockwise)
    void rotateRight() {
        switch (currentOrientation) {
            case North:
                currentOrientation = East;
                break;
            case South:
                currentOrientation = West;
                break;
            case East:
                currentOrientation = South;
                break;
            case West:
                currentOrientation = North;
                break;
        }
    }
     // Rotate upward (change direction to Up)
    void rotateUpward() {
        currentOrientation = Up;
    }

    // Rotate downward (change direction to Down)
    void rotateDownward() {
        currentOrientation = Down;
    }

    // Execute a sequence of commands
    void executeCommands(const vector<char>& commands) {
        for (char command : commands) {
            switch (command) {
                case 'f':
                    mvFd();
                    break;
                case 'b':
                    mvBd();
                    break;
                case 'l':
                    rotateLeft();
                    break;
                case 'r':
                    rotateRight();
                    break;
                case 'u':
                    rotateUpward();
                    break;
                case 'd':
                    rotateDownward();
                    break;
            }
        }
    }

    // Display the final position and direction of the spacecraft
    void displayPositionAndDirection() {
        cout << "Final Position: (" << currentPosition.xPos << ", " << currentPosition.yPos << ", " << currentPosition.zPos << ")\n";
        cout << "Final Direction: ";
        switch (currentOrientation) {
            case North:
                cout << "North\n";
                break;
            case South:
                cout << "South\n";
                break;
            case East:
                cout << "East\n";
                break;
            case West:
                cout << "West\n";
                break;
            case Up:
                cout << "Up\n";
                break;
            case Down:
                cout << "Down\n";
                break;
        }
    }
};

int main() {
    // Create a spacecraft object with an initial position and direction
    Spacecraft lunarCraft(0, 0, 0, North);

    // Define a sequence of commands to be executed
    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    // Execute the commands on the spacecraft
    lunarCraft.executeCommands(commands);

    // Display the starting position and direction, as well as the final position and direction
    cout << "Starting Position: (0, 0, 0)\n";
    cout << "Initial Direction: North\n";
    lunarCraft.displayPositionAndDirection();

    return 0;
}

