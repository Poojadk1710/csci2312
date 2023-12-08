#include <iostream>
    using std::cout;
    using std::endl;

#include <string>
    using std::string;

#include <array>
    using std::array;

#include "City.h"
#include "file_mngt.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::array<City, CITIES_TO_LOAD> listCities;

    loadCities(listCities);

    for (int cityIndex =0; cityIndex < CITIES_TO_LOAD; cityIndex++){
        cout << "------------- "<< cityIndex <<"th City ------------- \n";
        listCities[cityIndex].print();
        cout << "The Two Closest Cities are: " <<listCities[cityIndex].getClosestCity() <<" and " << listCities[cityIndex].getSecondClosestCity()<<endl;
        cout << "The Two Farthest Cities are: " <<listCities[cityIndex].getFarthestCity() <<" and " << listCities[cityIndex].getSecondFarthestCity()<<endl;
    }
    return 0;
}