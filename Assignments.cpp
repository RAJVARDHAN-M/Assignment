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