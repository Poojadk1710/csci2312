#ifndef FILE_MNGT_H
#define FILE_MNGT_H

#include <string>
    using std::string;

#include <array>
    using std::array;

#include "City.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int CITIES_TO_LOAD = 15;



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadCities(array<City,CITIES_TO_LOAD>& cities, const string& distFile="./src/distances.txt", const string& citiesFile="./src/cities.txt");

void loadCitiesNames(array<string,CITIES_TO_LOAD>& names, const string& filename="./src/cities.txt");

#endif