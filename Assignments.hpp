// Include the necessary headers for Catch2 and your Spacecraft class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "spacecraft.hpp" // Include your Spacecraft class header

TEST_CASE("Move Forward") {
    // Create a spacecraft at the origin facing North
    Spacecraft lunarCraft(0, 0, 0, North);

    // Move the spacecraft forward
    lunarCraft.moveForward();

    // Check if the new position is as expected
    REQUIRE(lunarCraft.getCurrentPosition().xPos == 0);
    REQUIRE(lunarCraft.getCurrentPosition().yPos == 1);
    REQUIRE(lunarCraft.getCurrentPosition().zPos == 0);
}
