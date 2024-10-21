#ifndef F1_DRIVER_H
#define F1_DRIVER_H

#include <iostream>
#include <string>
//#include "Exceptions.h"

class Driver {
private:
    std::string name;
    int age;
    int experience;
    int race_craft;
    int awareness;
    int pace;
    int rating;  // Calculat pe baza altor atribute prin formula: 0.25*experience + 0.25*race_craft + 0.2*awareness + 0.25*pace + 0.1(100-age)
    float salary;
    int upgradePoints = 0;
    int decreasePoints = 0;

    int calculateRating() const;


public:
    Driver(std::string name, int age, int experience, int race_craft, int awareness, int pace, float salary);
    Driver(const Driver& other);  // Copy constructor
    Driver& operator=(const Driver& other);  // Copy operator
    ~Driver();  // Destructor

    friend std::ostream& operator<<(std::ostream& os, const Driver& driver);

    void improveSkill(int expectedPosition, int racePosition);
    //void changeTeam();
    void decreaseSkill(int expectedPosition, int racePosition);
    int calculateMarketValue() const;

    const std::string& getName() const;
    int getRating() const;
    void setRating(int rating);
};

#endif
