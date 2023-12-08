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



std::string Patron::getName() const {
    return name;
}

std::string Patron::getAddress() const {
    return address;
}

std::string Patron::getPhoneNumber() const {
    return phoneNumber;
}


void Patron::setName(const std::string& name) {
    this->name = name;
}


void Patron::setAddress(const std::string& address) {
    this->address = address;
}

void Patron::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Patron::addCheckedBook(Book* aBook) {
    checkedBooks.push_back(aBook);
}

/*void Patron::removeCheckedBook(Book* aBook) {
    for (auto it = checkedBooks.begin(); it != checkedBooks.end(); ++it) {
        if (*it == aBook) {
            checkedBooks.erase(it);
            return;
        }
    }
}

bool Patron::isBookCheckedOutByPatron(Book* aBook) const {
    for (Book* book : checkedBooks) {
        if (book == aBook) {
            return true;
        }
    }
    return false;
}*/

void Patron::removeCheckedBook(Book* aBook){
    int pos = 0;
    for (Book* book: this->checkedBooks){
        if(book == aBook){
           this->checkedBooks.erase(checkedBooks.begin() + pos);
           break;
        }
        pos++;
    }
}

bool Patron::isBookCheckedOutByPatron(Book* aBook) const {
    for (Book* book: this->checkedBooks){
        if(book == aBook){
            return true;
        }
    }
    return false;
}