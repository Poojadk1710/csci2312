#ifndef BOOK_H
#define BOOK_H
#include "Patron.h"
#include <string>


class Patron;

class Book {
private:
    std::string title;
    Patron* checkedOutBy;

public:

    Book(const std::string& title);


    virtual ~Book();


    std::string getTitle() const;
    Patron* getCurrentPatron() const;


    void setTitle(const std::string& title);


    bool isCheckedOut() const;
    void checkOut(Patron* aPatron);
    void returnBook();

    virtual std::string toString() final;
    virtual std::string getBookSizeRepresentation() const = 0;

};

#endif