#include "AudioBook.h"

AudioBook::AudioBook(const std::string& title, int durationSeconds)
    : Book(title), durationSeconds(durationSeconds) {}


AudioBook::~AudioBook() {
}


int AudioBook::getDurationSeconds() const {
    return durationSeconds;
}