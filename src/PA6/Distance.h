#ifndef DISTANCE_H
#define DISTANCE_H

#include <string>
    using std::string;


class Distance {
public:
    Distance();
    explicit Distance(const string& cityName, int distance);

    string getCityName() const;
    int getDistance() const;

    void setDistance(int newDistance);

private:
    /**
     * //TODO #01:: [ToDo / DONE]
     * declare an integer for the distance and a string for the city name.
    */

    int distance;
    std::string cityName;

};


#endif
