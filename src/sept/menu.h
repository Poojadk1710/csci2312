#ifndef MENU_H
#define MENU_H

class Library;

class Menu {
public:
    Menu(); // Constructor
    void displayMenu(); // Displays the main menu
    void processChoice(Library& library, int choice); // Processes the user's choice
};

void mainMenu(Library& library);

#endif