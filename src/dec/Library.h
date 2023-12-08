#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"
#include "Patron.h"
#include "Loan.h"
#include "PrintedBook.h"
#include "AudioBook.h"
#include "EBook.h"

class Library {
private:
    std::string name;
    std::vector<Patron*> patrons;
    std::vector<Loan*> loans;
    std::vector<Book*> books;


public:

    Library(const std::string& name);

    ~Library();

    std::string getName() const;
    std::vector<Book*> getAudioBookList() const;
    std::vector<Book*> getPrintedBookList() const;
    std::vector<Book*> getEBookList() const;
    std::vector<Book*> getBookList() const;
    std::vector<Patron*> getPatronList() const;
    std::vector<Loan*> getLoanList() const;

    Book* searchBook(const std::string& title);
    Patron* searchPatron(const std::string& name);
    void addPrintedBook(const std::string& title, int numPages);
    void addEBook(const std::string& title, int sizeCharacters, int charsPerPage);
    void addAudioBook(const std::string& title, int durationSeconds);
    void addAudioBookSubMenu(std::string title, int duration);
    void addEBookSubMenu(std::string title, int sizeofCharacters, int charsofPerPage);

    void addPatron(const std::string& name, const std::string& address, const std::string& phoneNumber);
    void addPrintedBookSubMenu(std::string& title, int numPages);
    void checkOutBook(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay);
    void returnBook(Book* aBook, Patron* aPatron);
};

#endif