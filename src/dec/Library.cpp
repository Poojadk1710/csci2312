#include "Library.h"

Library::Library(const std::string& name) : name(name) {}

Library::~Library() {
    /*for (Book* book : books) {
        delete book;
        book = nullptr;
    }*/

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

Book* Library::searchBook(const std::string& title) {
    for (Book* book : books ) {
        if (book->getTitle() == title) {
            return book;
        }
    }
    return nullptr;
}


Patron* Library::searchPatron(const std::string& name) {
    for (Patron* patron : patrons) {
        if (patron->getName() == name) {
            return patron;
        }
    }
    return nullptr;
}

void Library::addPrintedBook(const std::string& title, int numPages) {

    if (searchBook(title) != nullptr) {
        throw std::invalid_argument("A book with the same title already exists");
    }

    Book* newPrintedBook = new PrintedBook(title, numPages);
    books.push_back(newPrintedBook);
}

void Library::addEBook(const std::string& title, int sizeCharacters, int charsPerPage) {
    if (searchBook(title) != nullptr) {
        throw std::invalid_argument("A book with the same title already exists");
    }

    Book* newEBook = new EBook(title, sizeCharacters, charsPerPage);
    books.push_back(newEBook);
}

void Library::addAudioBook(const std::string& title, int durationSeconds) {

    if (searchBook(title) != nullptr) {
        throw std::invalid_argument("A book with the same title already exists");
    }

    Book* newAudioBook = new AudioBook(title, durationSeconds);
    books.push_back(newAudioBook);
}

void Library::addPatron(const std::string& name, const std::string& address, const std::string& phoneNumber) {
    for (Patron* patron : patrons) {
        if (patron->getName() == name && patron->getAddress() == address && patron->getPhoneNumber() == phoneNumber) {
            throw std::invalid_argument("A patron with the same name already exists");
        }
    }
    Patron* newPatron = new Patron(name, address, phoneNumber);
    patrons.push_back(newPatron);
}

void Library::checkOutBook(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay) {
    if (aBook && aPatron) {
        if (!aBook->isCheckedOut()) {
            Loan* newLoan = new Loan(aBook, aPatron, dueYear, dueMonth, dueDay);
            loans.push_back(newLoan);
            aPatron->addCheckedBook(aBook);
            aBook->checkOut(aPatron);
        } else {
            std::cout << "Book is already checked out" << std::endl;
        }
    } else {
        std::cout << "Invalid book or patron." << std::endl;
    }
}

void Library::returnBook(Book* aBook, Patron* aPatron) {
    if (aBook && aPatron) {
        for (auto it = loans.begin(); it != loans.end(); ++it) {
            if ((*it)->getBook() == aBook && (*it)->getPatron() == aPatron) {
                aPatron->removeCheckedBook(aBook);
                aBook->returnBook();
                delete *it;
                loans.erase(it);
                return;
            }
        }
        std::cout << "Loan not found." << std::endl;
    } else {
        std::cout << "Invalid book or patron." << std::endl;
    }
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