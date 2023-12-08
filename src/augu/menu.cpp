
#include "menu.h"
#include "Library.h"
#include "Patron.h"
#include "Book.h"
#include <iostream>

/* Menu::menu() {}

void Menu::displayMenu() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "            Main Menu" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "1) Add Patron" << std::endl;
    std::cout << "2) Add Book" << std::endl;
    std::cout << "3) Search for Patron" << std::endl;
    std::cout << "4) Search for Book" << std::endl;
    std::cout << "99) EXIT" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

void Menu::processChoice(Library& library, int choice) {
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
            int numPages;
            std::cout << "Enter Book Title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter Number of Pages: ";
            std::cin >> numPages;
            library.addBook(title, numPages);
            std::cout << "Book added successfully." << std::endl;
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
                std::cout << "Book found: " << book->getTitle() << ", " << book->getNumPages() << " pages" << std::endl;
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
}

void mainMenu(Library& library) {
    Menu menu;
    int choice;

    do {
        menu.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 99) {
            std::cout << "Exiting the program." << std::endl;
            break;
        }

        menu.processChoice(library, choice); // Passes both library and choice

    } while (choice != 99);
} */


Menu::Menu() {} // Constructor definition

void Menu::displayMenu() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "            Main Menu" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "1) Add Patron" << std::endl;
    std::cout << "2) Add Book" << std::endl;
    std::cout << "3) Search for Patron" << std::endl;
    std::cout << "4) Search for Book" << std::endl;
    std::cout << "99) EXIT" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

void Menu::processChoice(Library& library, int choice) {
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
            int numPages;
            std::cout << "Enter Book Title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter Number of Pages: ";
            std::cin >> numPages;
            library.addBook(title, numPages);
            std::cout << "Book added successfully." << std::endl;
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
                std::cout << "Book found: " << book->getTitle() << ", " << book->getNumPages() << " pages" << std::endl;
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
}