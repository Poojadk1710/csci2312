#include <iostream>
    using std::cout;
    using std::endl;

#include <fstream>
    using std::ifstream;

#include <sstream>
    using std::stringstream;

#include <string>
    using std::string;

#include <array>
    using std::array;

#include "City.h"
#include "file_mngt.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadCitiesNames(array<string,CITIES_TO_LOAD>& names, const string& filename)
{
    ifstream file(filename);
    size_t id=0;
    string line, name, word;
    stringstream ss;

    getline(file, line);

    while (! file.eof()){
        ss.str("");
        ss.clear();
        ss<<line;
        ss>>id;
        name = "";
        while (ss>>word){
            if (name != "")
                name += " ";
            name += word;
        }

        if (id-1 < names.size())
            names[id-1] = name;

        getline(file, line);
    }

    file.close();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadCities(array<City,CITIES_TO_LOAD>& cities, const string& filename, const string& citiesFile)
{
    array<string,CITIES_TO_LOAD> cityNames;
    loadCitiesNames(cityNames, citiesFile);

    ifstream file(filename);

    for (int cInd =0; cInd<CITIES_TO_LOAD; cInd++){
        //loading all distances from cInd'th city
        int distance;
        cities[cInd].setName(cityNames[cInd]);
        for(int tInd=0; tInd<CITIES_TO_LOAD; tInd++){
            // Loading the distance from city cInd to city tInd
            file >> distance;                               // get the distance from cInd to tInd
            cities[cInd].setDistance(cityNames[tInd],distance);
        }
    }

    file.close();
}
