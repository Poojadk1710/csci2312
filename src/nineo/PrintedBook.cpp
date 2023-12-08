#include "PrintedBook.h"

PrintedBook::PrintedBook(const std::string& title, int numPages) : Book(title), numPages(numPages) {}

PrintedBook::~PrintedBook() {
}

int PrintedBook::getNumPages() const {
    return numPages;
}