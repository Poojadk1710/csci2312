#include "Book.h"
#include "Patron.h"
#include "Loan.h"

Book::Book(const std::string &title, int numPages) {
    this->title = title;
    this->numPages = numPages;
    this->checkedOutBy = nullptr;
}

Book::~Book() {
    this->checkedOutBy = nullptr;

}

std::string Book::getTitle() const {
    return title;
}

Patron* Book::getCurrentPatron() const {
    return checkedOutBy;
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

bool Book::isCheckedOut() const {
 if (this->checkedOutBy != nullptr)
    {
        return true;
    }
    return false;
}


void Book::checkOut(Patron* aPatron) {
    checkedOutBy = aPatron;
}

void Book::returnBook() {
    checkedOutBy = nullptr;
}