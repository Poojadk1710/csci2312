#include <string>
    using std::string;

#include "Distance.h"

/**
 * //TODO #02: [ToDo / DONE]
 * Implement the class methods.
*/

// Default constructor
Distance::Distance() {
    distance = 0;
    cityName = "";
}

// Overloaded Constructor
Distance::Distance(const std::string &cityName, int distance) {
    this->cityName = cityName;
    this->distance = distance;
}

// getters
std::string Distance::getCityName() const {
    return cityName;
}

int Distance::getDistance() const {
    return distance;
}

// setters
void Distance::setDistance(int newDistance) {
    distance = newDistance;
}