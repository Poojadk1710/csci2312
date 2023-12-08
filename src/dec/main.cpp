#include "Book.h"
#include "AudioBook.h"
#include<iostream>
    using std::cout;
    using std::endl;

int main()
{
    // Library lbr = Library("Auraria");

    // mainMenu(lbr);

    Book* book = new AudioBook("TEST", 1000);
    cout << book->toString() << endl;

    return 0;
}