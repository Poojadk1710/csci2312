#include "Patron.h"

Patron::Patron(const std::string& name, const std::string& address, const std::string& phoneNumber )
    : name(name), address(address), phoneNumber(phoneNumber) {}

Patron::~Patron() {
     for (Book* book: this->listCheckedBooks){
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

void Patron::setName(const std::string& newName) {
    name = newName;
}

void Patron::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void Patron::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Patron::addCheckedBook(Book* aBook)
{
    this->listCheckedBooks.push_back(aBook);
}

void Patron::removeCheckedBook(Book* aBook){
    int pos = 0;
    for (Book* book: this->listCheckedBooks){
        if(book == aBook){
           this->listCheckedBooks.erase(listCheckedBooks.begin() + pos);
           break;
        }
        pos++;
    }
}

bool Patron::isBookCheckedOutByPatron(Book* aBook){
    for (Book* book: this->listCheckedBooks){
        if(book == aBook){
            return true;
        }
    }
    return false;
}