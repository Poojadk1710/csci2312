#include "Time.h"
#include <iomanip>

Time::Time() : hours(0), minutes(0), seconds(0) {}

// Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

void Time::load(const std::string& s) {
    std::stringstream ss(s);
    ss >> hours >> minutes >> seconds;
}

std::string Time::toUniversalStandard() const {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hours << ":"
       << std::setw(2) << std::setfill('0') << minutes << ":"
       << std::setw(2) << std::setfill('0') << seconds;
    return ss.str();
}

// std::ostream& operator<<(std::ostream& os, const Time& time) {
//     os << std::setw(2) << std::setfill('0') << ((time.hours == 0 || time.hours == 12) ? 12 : time.hours % 12) << ":"
//        << std::setw(2) << std::setfill('0') << time.minutes << ":"
//        << std::setw(2) << std::setfill('0') << time.seconds << " "
//        << ((time.hours < 12) ? "AM" : "PM") << "\t"
//        << time.hours << " " << time.minutes << " " << time.seconds;
//     return os;

    int Time::getHours() const {
    return hours;
    }

    int Time::getMinutes() const {
    return minutes;
    }

    int Time::getSeconds() const {
    return seconds;
    }


    std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << std::setfill('0') << std::setw(2) << ((t.hours == 0 || t.hours == 12) ? 12 : t.hours % 12) << ":"
       << std::setw(2) << t.minutes << ":" << std::setw(2) << t.seconds;
    return os;
}