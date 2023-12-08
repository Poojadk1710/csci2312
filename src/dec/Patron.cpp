#include "Patron.h"
#include <iostream>

Patron::Patron(const std::string& name, const std::string& address, const std::string& phoneNumber)
    : name(name), address(address), phoneNumber(phoneNumber) {}

Patron::~Patron() {
    for (Book* book : this->checkedBooks) {
        //std::cout << "Book title: " << book->getTitle() << std::endl;
        book = nullptr;
    }

}
