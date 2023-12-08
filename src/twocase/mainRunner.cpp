#include "mainRunner.h"

int mainRunner(){

    //stores user input
    std::string bookTitle;
    int bookPubYear;
    int bookNumOfPages;

    std::cout << " Please input title : " << std::endl;
    std::getline(std::cin, bookTitle);

    std::cout << "Input pub year : " << std::endl;
    std::cin >> bookPubYear;

    std::cout << "Input num of pages : " << std::endl;
    std::cin >> bookNumOfPages;

    //Create Book Object
    Book myBook(bookTitle, bookPubYear, bookNumOfPages);

    //Output of the Book's title and estimated weight
    std::cout << myBook.getTitle() << " is about " << myBook.estimatedBookWeight() << " ounces." << std::endl;

    return 0;
}