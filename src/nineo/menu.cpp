#include "menu.h"
#include "Library.h"
#include "Patron.h"
#include "Book.h"
#include <iostream>


void mainMenu(Library& library) {
    int choice;
    int bookChoice;

    do {
            std::cout << "---------------------------------" << std::endl;
            std::string title;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "            Add Menu" << std::endl;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "1) Add Patron" << std::endl;
            std::cout << "2) Add Book" << std::endl;
            std::cout << "3) Search for Patron" << std::endl;
            std::cout << "4) Search for Book" << std::endl;
            std::cout << "5) Check Out Book " << std::endl;
            std::cout << "6) Return Book" << std::endl;
            std::cout << "99) EXIT" << std::endl;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

        switch (choice) {
        case 1: {

            std::string name, address, phoneNumber;
            std::cout << "Enter Patron's Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter Patron's Address: ";
            std::getline(std::cin, address);
            std::cout << "Enter Patron's Phone Number: ";
            std::getline(std::cin, phoneNumber);
            library.addPatron(name, address, phoneNumber);
            std::cout << "Patron added successfully." << std::endl;
            break;
        }
        case 2: {
            // Adds Book
            std::string title;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "            Add Book Menu" << std::endl;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "1) Add Printed Book" << std::endl;
            std::cout << "2) Add Ebook" << std::endl;
            std::cout << "3) Add Audiobook" << std::endl;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin.ignore();
            std::cin >> choice;

            switch(choice){
                case 1: {
                std::string title;
                int numPages;
                std::cout << "Enter PrintedBook's Name: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter PrintedBook's title: ";
                std::cin >> numPages;
                std::cout << "Enter PrintedBook's number of Pages: ";
                library.addPrintedBook(title, numPages);
                std::cout << "PrintedBook added successfully." << std::endl;
                break;
                }
                case 2: {
                std::string title;
                int sizeofCharacters;
                int charsofPerPage ;
                std::cout << "Enter EBook's Name: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter EBook's title: ";
                std::cin >> sizeofCharacters;
                std::cout << "Enter EBook's size of Characters: ";
                std::cin >> charsofPerPage;
                std::cout << "Enter EBook's Chars per page: ";
                library.addEBook(title, sizeofCharacters, charsofPerPage);
                std::cout << "EBook added successfully." << std::endl;
                break;
                }
                case 3: {
                std::string title;
                int duration;
                std::cout << "Enter AudioBook's Name: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter AudioBook's duration: ";
                std::cin >> duration;
                library.addAudioBook(title, duration);
                std::cout << "AudioBook added successfully." << std::endl;
                break;

                }

            }
            break;
        }
        case 3: {
            // Searchs for Patron
            std::string name;
            std::cout << "Enter Patron's Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            Patron* patron = library.searchPatron(name);
            if (patron) {
                std::cout << "Patron found: " << patron->getName() << ", " << patron->getAddress() << ", " << patron->getPhoneNumber() << std::endl;
            } else {
                std::cout << "Patron not found." << std::endl;
            }
            break;
        }
        case 4: {
            // Searchs for Book
            std::string title;
            std::cout << "Enter book's title to search: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            Book* book = library.searchBook(title);
            if (book) {
                std::cout << "Book found: " << book->getTitle() << std::endl;
            } else {
                std::cout << "Book not found." << std::endl;
            }
            break;
        }

        case 99: {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }

    } while (choice != 99);
}