#include "Book.h"
#include "Patron.h"


Book::Book(const std::string& title) : title(title), checkedOutBy(nullptr) {}


Book::~Book() {
    checkedOutBy = nullptr;

}


std::string Book::getTitle() const {
    return title;
}


void Book::setTitle(const std::string& title) {
    this->title = title;
}


void Book::checkOut(Patron* aPatron) {
    checkedOutBy = aPatron;
}

void Book::returnBook() {
    checkedOutBy = nullptr;
}


bool Book::isCheckedOut() const {
    return checkedOutBy != nullptr;
}


Patron* Book::getCurrentPatron() const {
    return checkedOutBy;
}

std::string Book::toString() {
    return "'" + title + "'" + getBookSizeRepresentation();
}