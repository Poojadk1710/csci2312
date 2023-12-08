#ifndef PATRON_H
#define PATRON_H

#include <string>

class Patron {
private:
    std::string name;
    std::string address;
    std::string phoneNumber;

public:
    Patron(const std::string& name, const std::string& address, const std::string& phoneNumber);
    ~Patron();

    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setPhoneNumber(const std::string& phoneNumber);
};

#endif