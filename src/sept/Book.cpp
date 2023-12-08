#include "Book.h"

Book::Book(const std::string& title, int numPages) : title(title), numPages(numPages) {}

Book::~Book() {
}

std::string Book::getTitle() const {
    return title;
}

int Book::getNumPages() const {
    return numPages;
}

void Book::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Book::setNumPages(int newNumPages) {
    numPages = newNumPages;
}