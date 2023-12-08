#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>

#include "Book.h"
#include "Patron.h"
#include "Loan.h"

class Book;
class Patron;

class Library {
private:
    std::string name;
    std::vector<Book*> books;
    std::vector<Patron*> patrons;
    std::vector<Loan*> loans;

public:
    Library(const std::string& name);
    ~Library();

    std::string getName() const;
    std::vector<Book*> getBookList() const;
    std::vector<Patron*> getPatronList() const;
    std::vector<Loan*> getLoanList() const;


    void addBook(const std::string& title, int numPages);
    void addPatron(const std::string& name, const std::string& address, const std::string& phoneNumber);

    Book* searchBook(const std::string& title);
    Patron* searchPatron(const std::string& name);
    void checkOutBook(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay);
    void returnBook(Book* aBook, Patron* aPatron);
};

#endif