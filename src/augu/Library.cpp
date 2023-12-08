#include "Library.h"


Library::Library(const std::string& name) : name(name) {}

Library::~Library() {

    for (Book* book : books) {
        delete book;
        book = nullptr;
    }
    for (Patron* patron : patrons) {
        delete patron;
        patron = nullptr;
    }
     for (Loan* loan : loans) {
        delete loan;
        loan = nullptr;
    }
}

std::string Library::getName() const {
    return name;
}

std::vector<Book*> Library::getBookList() const {
    return books;
}

std::vector<Patron*> Library::getPatronList() const {
    return patrons;
}

std::vector<Loan*> Library::getLoanList() const {
    return loans;
}

void Library::addBook(const std::string& title, int numPages) {

    if (searchBook(title) == nullptr) {
        Book* newBook = new Book(title, numPages);
        books.push_back(newBook);
    }

}

void Library::addPatron(const std::string& name, const std::string& address, const std::string& phoneNumber) {

    if (searchPatron(name) == nullptr) {
        Patron* newPatron = new Patron(name, address, phoneNumber);
        patrons.push_back(newPatron);
    }

}

Book* Library::searchBook(const std::string& title) {
    for (Book* book : books) {
        if (book->getTitle() == title) {
            return book;
        }
    }
    return nullptr;  // Book not found
}

Patron* Library::searchPatron(const std::string& name) {
    for (Patron* patron : patrons) {
        if (patron->getName() == name) {
            return patron;
        }
    }
    return nullptr;  // Patron not found
}



void Library::checkOutBook(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay) {

    if (aBook && aPatron) {

        if (!aBook->isCheckedOut()) {
            Loan* newLoan = new Loan(aBook, aPatron, dueYear, dueMonth, dueDay);
            loans.push_back(newLoan);

            aBook->checkOut(aPatron);
            aPatron->addCheckedBook(aBook);
        }
    }
}

void Library::returnBook(Book* aBook, Patron* aPatron) {

    if (aBook && aPatron) {
        for (Loan* loan : loan) {
            if (loan->getBook() == aBook && loan->getPatron() == aPatron) {
                loans.erase(std::remove(loans.begin(), loans.end(), loan), loans.end());
                delete loan;

                aBook->returnBook();
                aPatron->removeCheckedBook(aBook);

                break;
            }
        }
    }
}