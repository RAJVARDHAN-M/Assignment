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
