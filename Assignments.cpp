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
