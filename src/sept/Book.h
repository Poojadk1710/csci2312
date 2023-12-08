#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    int numPages;

public:
    Book(const std::string& title, int numPages);
    ~Book();

    std::string getTitle() const;
    int getNumPages() const;
    void setTitle(const std::string& title);
    void setNumPages(int numPages);
};

#endif