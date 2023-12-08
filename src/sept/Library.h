#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>

class Book;
class Patron;

class Library {
private:
    std::string name;
    std::vector<Book*> books;
    std::vector<Patron*> patrons;

public:
    Library(const std::string& name);
    ~Library();

    std::string getName() const;
    std::vector<Book*> getBookList() const;
    std::vector<Patron*> getPatronList() const;

    Book* searchBook(const std::string& title);
    Patron* searchPatron(const std::string& name);
    void addBook(const std::string& title, int numPages);
    void addPatron(const std::string& name, const std::string& address, const std::string& phoneNumber);
};

#endif