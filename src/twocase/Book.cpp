#include "Book.h"

//Implementing the constructor
Book::Book(std::string x, int y, int z)
{
    title = x;
    pubYear = y;
    numOfPages = z;
}

//getters
std::string Book::getTitle(){
    return title;
}

int Book::getPubYear(){
    return pubYear;
}

int Book::getNumOfPages(){
    return numOfPages;
}

//setters
void Book::setTitle(std::string x){
    title = x;
}

void Book::setPubYear(int y){
    pubYear = y;

}

void Book::setNumOfPages(int z){
    numOfPages = z;

}

//Function to calculate estimated book weight
float Book::estimatedBookWeight(){
    if(numOfPages%2 != 0){
        numOfPages++;
    }
    return ((numOfPages) * 0.176f)/2;
}