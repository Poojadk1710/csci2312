#ifndef CITY_H
#define CITY_H

#include <string>
    using std::string;

#include <vector>
    using std::vector;

#include "Distance.h"



class City {
public:
    City();
    explicit City(const string& cityName);

    string getName() const;
    void setName(const string& cityName);

    void setDistance(const string& targetCityName, int distance);
    void addDetour(const string& targetCityName, int detourDistance);

    int distanceTo(const string& cityName) const;
    double tripCost(const string& targetCityName, const double mpg, const double gasCost) const;
    double getAverageDistance() const;

    string getClosestCity() const;
    string getFarthestCity() const;
    string getSecondClosestCity() const;
    string getSecondFarthestCity() const;

    void print() const;

private:
    /**
     * //TODO #03: [ToDo / DONE]
     * Declare the attributes(variables) for the class:
     * - a string for the City name.
     * - an integer for the countOfDistances currently stored. Needs to keep updated as you add new distances from the city.
     * - a vector to store the list of distances. Distances are represented as Distance objects.
    */

   std::string name; // City name
   int countOfDistance; //Count of Distances
   std::vector<Distance> distances; // A vector of Distance object

};


#endif
