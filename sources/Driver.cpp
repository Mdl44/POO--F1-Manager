#include "Driver.h"

// Constructor parametrizat
Driver::Driver(std::string name, int age, int experience, int race_craft, int awareness, int pace, float salary)
    : name(std::move(name)), age(age), experience(experience), race_craft(race_craft), awareness(awareness), pace(pace), salary(salary), upgradePoints(0), decreasePoints(0) {
    rating = calculateRating();
}

// Constructor de copiere
Driver::Driver(const Driver& other) = default;

// Operator de copiere
Driver& Driver::operator=(const Driver& other) = default;

// Destructor
Driver::~Driver() = default;

int Driver::calculateRating() const {
    return static_cast<int>(0.25 * experience + 0.25 * race_craft + 0.2 * awareness + 0.25 * pace + 0.1 * (100 - age));
}


void Driver::improveSkill() {
    upgradePoints++;

    if (upgradePoints >= 5) {
        upgradePoints = 0;
        experience += 2;
        race_craft += 1;
        awareness += 1;
        pace += 1;

        rating = calculateRating();
        std::cout << "Driver's skills have improved, and rating has been updated!\n";
    } else {
        std::cout << "Driver earned an upgrade point! Current points: " << upgradePoints << "\n";
    }
}

void Driver::decreaseSkill() {
    decreasePoints++;

    if (decreasePoints >= 5) {
        decreasePoints = 0;
        experience = std::max(0, experience - 2);
        race_craft = std::max(0, race_craft - 1);
        awareness = std::max(0, awareness - 1);
        pace = std::max(0, pace - 1);

        rating = calculateRating();
        std::cout << "Driver's skills have decreased due to poor performance, and rating has been updated!\n";
    }
}

int Driver::calculateMarketValue() const {
    return static_cast<int>((rating - 55) * 10000);
}

const std::string& Driver::getName() const {
    return name;
}

int Driver::getRating() const {
    return rating;
}

void Driver::setRating(int newRating) {
    if (newRating < 0 || newRating > 100) {
        throw std::invalid_argument("Rating-ul trebuie să fie între 0 și 100.");
    }
    rating = newRating;
}

std::ostream& operator<<(std::ostream& os, const Driver& driver) {
    os << "Nume Driver: " << driver.name << "\nVarsta: " << driver.age << "\nExperienta: " << driver.experience
       << "\nRace Craft: " << driver.race_craft << "\nAwareness: " << driver.awareness
       << "\nPace: " << driver.pace << "\nRating: " << driver.rating;
    return os;
}
