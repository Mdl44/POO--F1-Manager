#include <iostream>
#include "Driver.h"

int main() {
    Driver driver1("Lewis Hamilton", 38, 95, 90, 88, 93, 40.0f);
    int expectedPosition = 1;
    int racePosition = 5;

    std::cout << "Driver Details:\n";
    std::cout << driver1 << std::endl;
    if(expectedPosition < racePosition) {
        driver1.decreaseSkill(expectedPosition, racePosition);
        driver1.decreaseSkill(expectedPosition, racePosition);
        driver1.decreaseSkill(expectedPosition, racePosition);
        driver1.decreaseSkill(expectedPosition, racePosition);
        driver1.decreaseSkill(expectedPosition, racePosition);
    } else {
        driver1.improveSkill(expectedPosition, racePosition);
        driver1.improveSkill(expectedPosition, racePosition);
        driver1.improveSkill(expectedPosition, racePosition);
        driver1.improveSkill(expectedPosition, racePosition);
        driver1.improveSkill(expectedPosition, racePosition);
    }
    expectedPosition = 1;
    racePosition = 1;
    if(expectedPosition < racePosition) {
        driver1.decreaseSkill(expectedPosition, racePosition);
        driver1.decreaseSkill(expectedPosition, racePosition);
        driver1.decreaseSkill(expectedPosition, racePosition);
        driver1.decreaseSkill(expectedPosition, racePosition);
        driver1.decreaseSkill(expectedPosition, racePosition);
    } else {
        driver1.improveSkill(expectedPosition, racePosition);
        driver1.improveSkill(expectedPosition, racePosition);
        driver1.improveSkill(expectedPosition, racePosition);
        driver1.improveSkill(expectedPosition, racePosition);
        driver1.improveSkill(expectedPosition, racePosition);
    }
    std::cout << "\nSkill Update:\n";
    std::cout << driver1 << std::endl;

    // driver1.changeTeam();


    return 0;
}
