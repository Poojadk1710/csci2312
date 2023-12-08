#include "AudioBook.h"

AudioBook::AudioBook(const std::string& title, int durationSeconds)
    : Book(title), durationSeconds(durationSeconds) {}


AudioBook::~AudioBook() {
}


int AudioBook::getDurationSeconds() const {
    return durationSeconds;
}

std::string AudioBook::getBookSizeRepresentation() const {
    int minutes = durationSeconds / 60; // Calculate minutes
    int seconds = durationSeconds % 60; // Calculate remaining seconds
    return " has a duration of " + std::to_string(minutes) +  ":" +
           (seconds < 10 ? "0" : "") + std::to_string(seconds) +".";
}