#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <cmath>

class Book{

private:
    std::string title;
    int pubYear;
    int numOfPages;

public:
    explicit Book(std::string theTitle, int thePubYear, int theNumOfPages); //constructor
    float estimatedBookWeight();

    //getters
    std::string getTitle();
    int getPubYear();
    int getNumOfPages();

    //setters
    void setTitle(std::string x);
    void setPubYear(int y);
    void setNumOfPages(int z);


};


#endif