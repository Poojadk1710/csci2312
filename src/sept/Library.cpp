#include "Library.h"
#include "Book.h"
#include "Patron.h"

Library::Library(const std::string& name) : name(name) {}

Library::~Library() {

    for (Book* book : books) {
        delete book;
    }
    for (Patron* patron : patrons) {
        delete patron;
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