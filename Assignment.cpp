#include <iostream>
#include <vector>

using namespace std;

// Define a structure to represent coordinates in 3D space
struct Coordinate {
    int x, y, z;
};

// Define an enumeration for cardinal directions and 3D orientation
enum Direction { North, South, East, West, Up, Down };

// Create a class to simulate a 3D spacecraft
class Spacecraft {
private:
    Coordinate position;   // Store the current position (x, y, z)
    Direction facing;      // Store the current direction or orientation

public:
    // Constructor to initialize the spacecraft's position and direction
    Spacecraft(int x, int y, int z, Direction initialDirection) {
        position.x = x;
        position.y = y;
        position.z = z;
        facing = initialDirection;
    }

    // Move forward in the current direction
    void mvfd() {
        switch (facing) {
            case North:
                position.y++;
                break;
            case South:
                position.y--;
                break;
            case East:
                position.x++;
                break;
            case West:
                position.x--;
                break;
            case Up:
                position.z++;
                break;
            case Down:
                position.z--;
                break;
        }
    }

    // Move backward in the current direction
    void mvbd() {
        switch (facing) {
            case North:
                position.y--;
                break;
            case South:
                position.y++;
                break;
            case East:
                position.x--;
                break;
            case West:
                position.x++;
                break;
            case Up:
                position.z--;
                break;
            case Down:
                position.z++;
                break;
        }
    }

    // Turn left (change direction counterclockwise)
    void tnlt() {
        switch (facing) {
            case North:
                facing = West;
                break;
            case South:
                facing = East;
                break;
            case East:
                facing = North;
                break;
            case West:
                facing = South;
                break;
        }
    }

    // Turn right (change direction clockwise)
    void tnrt() {
        switch (facing) {
            case North:
                facing = East;
                break;
            case South:
                facing = West;
                break;
            case East:
                facing = South;
                break;
            case West:
                facing = North;
                break;
        }
    }

    // Turn upward (change direction to Up)
    void tnud() {
        facing = Up;
    }

    // Turn downward (change direction to Down)
    void tndd() {
        facing = Down;
    }

    // Execute a sequence of commands
    void executeCommands(const vector<char>& commands) {
        for (char command : commands) {
            switch (command) {
                case 'f':
                    mvfd();
                    break;
                case 'b':
                    mvbd();
                    break;
                case 'l':
                    tnlt();
                    break;
                case 'r':
                    tnrt();
                    break;
                case 'u':
                    tnud();
                    break;
                case 'd':
                    tndd();
                    break;
            }
        }
    }

    // Display the final position and direction of the spacecraft
    void displayPositionAndDirection() {
        cout << "Final Position: (" << position.x << ", " << position.y << ", " << position.z << ")\n";
        cout << "Final Direction: ";
        switch (facing) {
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
    Spacecraft spacecraft(0, 0, 0, North);

    // Define a sequence of commands to be executed
    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    // Execute the commands on the spacecraft
    spacecraft.executeCommands(commands);

    // Display the starting position and direction, as well as the final position and direction
    cout << "Starting Position: (0, 0, 0)\n";
    cout << "Initial Direction: North\n";
    spacecraft.displayPositionAndDirection();

    return 0;
}
