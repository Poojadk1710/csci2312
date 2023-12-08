#include "Patron.h"

Patron::Patron(const std::string& name, const std::string& address, const std::string& phoneNumber)
    : name(name), address(address), phoneNumber(phoneNumber) {}

Patron::~Patron() {
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