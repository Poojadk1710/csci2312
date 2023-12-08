#ifndef LOAN_H
#define LOAN_H

#include "Book.h"
#include "Patron.h"
#include "Date.h"

class Loan {
private:
    Book* borrowedBook;
    Patron* checkedOutPatron;
    Date dueDate;

public:
    Loan(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay);

    ~Loan();

    Book* getBook() const;
    Patron* getPatron() const;
    Date getDueDate() const;
};

#endif