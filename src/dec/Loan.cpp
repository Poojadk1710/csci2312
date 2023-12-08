#include "Loan.h"

Loan::Loan(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay)
    : borrowedBook(aBook), checkedOutPatron(aPatron), dueDate(dueYear, dueMonth, dueDay) {}

Loan::~Loan() {
}

Book* Loan::getBook() const {
    return borrowedBook;
}


Patron* Loan::getPatron() const {
    return checkedOutPatron;
}

Date Loan::getDueDate() const {
    return dueDate;
}