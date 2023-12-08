#include <iostream>
#include "hello.h"
#include "goodbye.h"

int main()
{
     // Calling the function getGreeting() from hello.h
    std::string s = getGreeting(); // Storing the returned greeting message in variable 's'
    std::cout << s << std::endl;

    // Calling the function getFarewell() from goodbye.h
    std::string t = getFarewell();  // Storing the returned farewell message in variable 't'
    std::cout << t << std::endl;

    return 0;
}