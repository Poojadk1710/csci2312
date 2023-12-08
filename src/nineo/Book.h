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


    ~Book();


    std::string getTitle() const;
    Patron* getCurrentPatron() const;


    void setTitle(const std::string& title);


    bool isCheckedOut() const;
    void checkOut(Patron* aPatron);
    void returnBook();
};

#endif