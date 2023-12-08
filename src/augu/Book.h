#ifndef BOOK_H
#define BOOK_H
#include "Patron.h"
#include <string>


class Patron;

class Book {
private:
    std::string title;
    int numPages;
    Patron* checkedOutBy;

public:
    //constructor
    Book(const std::string& title, int numPages);

    //destructor
    ~Book();

    //getters
    std::string getTitle() const;
    int getNumPages() const;
    Patron* getCurrentPatron() const; // Declaration for getCurrentPatron()

    //setters
    void setTitle(const std::string& title);
    void setNumPages(int numPages);

    //functions
    bool isCheckedOut() const;
    void checkOut(Patron* aPatron); // Declaration for checkOut()
    void returnBook();
};

#endif