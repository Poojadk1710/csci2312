#ifndef MENU_H
#define MENU_H

#include "Library.h"

class Library;

class Menu {
public:
    Menu(); // Constructor
    void displayMenu(); // Displays the main menu
    void processChoice(Library& library, int choice); // Processes the user's choice
    static void mainMenu(Library& library);


};


void mainMenu(Library& library);

#endif