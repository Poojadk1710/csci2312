#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
#include <sstream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    // Time(int h, int m, int s);
    void load(const std::string& s);
    std::string toUniversalStandard() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif // TIME_H