#include <iostream>
    using std::cout;
    using std::endl;

#include <string>
    using std::string;

#include "City.h"
#include <climits>

City::City()
{
    /**
     * //TODO #04: [ToDo / DONE]
     * Initializes the name and count with default values.
    */

    name = "";
    countOfDistance = 0;
}

City::City(const string &cityName)
{
    /**
     * //TODO #05: [ToDo / DONE]
     * Initializes the name with the given one. There will no distances at this time.
    */

    name = cityName;
    countOfDistance = 0;
}


/**
 * //TODO #06: [ToDo / DONE]
 * Implement getter and setter for city name.
*/

// Setter for City Name
void City::setName(const std::string &cityName) {
    name = cityName;
}

// Getter for City Name
std::string City::getName() const {
    return name;
}

void City::setDistance(const string &targetCityName, int distance)
{
    /**
     * //TODO #07: [ToDo / DONE]
     * 1) checks that there is no distance object for the given target city in the distances list.
     * 1.1) if there is one, the method will update the distance
     * 1.2) if there isn't one, then a new distance object for the target city will be created and added to the list.
     *      this needs to keep the count of distances updated.
    */

    // Iterating through the distance objects
    for (auto &dist : distances) {
        if (dist.getCityName() == targetCityName) {
            dist.setDistance(distance);
        }
    }
    distances.push_back(Distance(targetCityName, distance));
    countOfDistance++;
}

void City::addDetour(const string &targetCityName, int detourDistance)
{
    /**
     * //TODO #08: [ToDo / DONE]
     * 1) A detour is in place for the target city. This will increase the travel distance.
     * 2) make sure the detour increases the distance to the city.
     * 3) if a distance for the target city is not found, then do nothing.
    */

    // Iterating through the distance objects
    for (auto &dist : distances) {
        if (dist.getCityName() == targetCityName) {
            dist.setDistance(dist.getDistance() + detourDistance);
        }
    }
}

int City::distanceTo(const string &cityName) const
{
    /**
     * //TODO #09: [ToDo / DONE]
     * 1) returns the distance to the given city name.
     * 2) if no distance is found, returns -1
    */

    // Iterating through the distance objects
    for (const auto &dist : distances) {
        if (dist.getCityName() == cityName) {
            return dist.getDistance();
        }
    }
    return -1;
}

double City::tripCost(const string &targetCityName, const double mpg, const double gasCost) const
{
    /**
     * //TODO #10: [ToDo / DONE]
     * returns the estimate cost of the trip.
     * To find the distance to the target use the distanceTo method.
     * Computation Formula is: distance / MPG x GallonPriceß
    */

    int distance = distanceTo(targetCityName);
    if (distance == -1) {
        std::cerr << "Error: Target city not found for trip cost calculation." << std::endl;
        return 0.0;
    }
    return (static_cast<double>(distance) / mpg) * gasCost;
}

double City::getAverageDistance() const
{
    /**
     * //TODO #11: [ToDo / DONE]
     * returns the average tavel distance to all cities.
     * (if theres a record to itself, it should be included as well)
    */

    if (countOfDistance == 0) {
        return 0.0;
    }
    int totalDistance = 0;

    // Iterating through the distance objects
    for (const auto &dist : distances) {
        totalDistance += dist.getDistance();
    }
    return static_cast<double>(totalDistance) / countOfDistance;
}

string City::getClosestCity() const
{
    /**
     * //TODO #12: [ToDo / DONE]
     * Computes the closest city you can travel to from this city.
     * E.g., From Denver you can travel to Boulder, Colorado Springs and Pueblo.
     * Then Boulder is the closest city from Denver.
     * Only consider cities which travel distance is at least one mile.
    */

    int minDistance = INT_MAX;
    std::string city; // The name of the closest city will be stored in this variable

    // Iterating through the distance objects
    for (const auto &dist : distances) {
        if (dist.getDistance() < minDistance && dist.getDistance() > 0) {
            minDistance = dist.getDistance();
            city = dist.getCityName();
        }
    }
    return city;
}

string City::getFarthestCity() const
{
    /**
     * //TODO #13: [ToDo / DONE]
     * Returns the city name which is the farthest to travel from this city.
     * E.g., From Denver you can travel to Boulder, Colorado Springs and Pueblo.
     * Then Pueblo is the fartherst city from Denver.
    */

    int maxDistance = 0;
    std::string city; // The name of the farthest city will be stored in this variable

    // Iterating through the distance objects
    for (const auto &dist : distances) {
        if (dist.getDistance() > maxDistance) {
            maxDistance = dist.getDistance();
            city = dist.getCityName();
        }
    }
    return city;
}

string City::getSecondClosestCity() const
{
    /**
     * //TODO #14: [ToDo / DONE]
     * Computes the second closest city you can travel to from this city.
     * E.g., From Denver you can travel to Boulder, Colorado Springs and Pueblo.
     * Then Boulder is the closest city from Denver. The second closest is Colorado Springs.
     * Only consider cities which travel distance is at least one mile.
    */

    int minDistance = INT_MAX;
    int secondMinDistance = INT_MAX;
    std::string closestCity;
    std::string secondClosestCity;

    // Iterating through the distance objects
    for (const auto &dist : distances) {
        if (dist.getDistance() < minDistance && dist.getDistance() > 0) {
            secondMinDistance = minDistance;
            minDistance = dist.getDistance();
            secondClosestCity = closestCity;
            closestCity = dist.getCityName();
        }
        else if (dist.getDistance() < secondMinDistance && dist.getDistance() > 0) {
            secondMinDistance = dist.getDistance();
            secondClosestCity = dist.getCityName();
        }
    }
    return secondClosestCity;
}



string City::getSecondFarthestCity() const
{
    /**
     * //TODO #15: [ToDo / DONE]
     * Returns the city name which is the second farthest to travel from this city.
     * E.g., From Denver you can travel to Boulder, Colorado Springs and Pueblo.
     * Then Colorado Spring is the second fartherst city from Denver.
    */

    int maxDistance = INT_MIN;
    int secondMaxDistance = INT_MIN;
    std::string farthestCity;
    std::string secondFarthestCity;

    // Iterating through the distance objects
    for (const auto &dist : distances) {
        if (dist.getDistance() > maxDistance) {
            secondMaxDistance = maxDistance;
            maxDistance = dist.getDistance();
            secondFarthestCity = farthestCity;
            farthestCity = dist.getCityName();
        }
        else if (dist.getDistance() > secondMaxDistance) {
            secondMaxDistance = dist.getDistance();
            secondFarthestCity = dist.getCityName();
        }
    }
    return secondFarthestCity;
}


void City::print() const
{
    /**
     * //TODO #16: [ToDo / DONE]
     * For each city you can travel from this city print a line with the following information:
     * The Distance From: <this_city_name> To: <city_name> is <distance> miles.
     * Example:
     * The Distance From: Denver To: Boulder is 29 miles.
     * The Distance From: Denver To: Colorado Springs is 69 miles.
    */

    // Iterating through the distance objects
    for (const auto &dist : distances) {
        std::cout << "The Distance From: " << name << " To: " << dist.getCityName() << " is " << dist.getDistance() << " miles." << std::endl;
    }
}