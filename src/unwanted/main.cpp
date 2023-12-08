#include <iostream>


int main()
{
    int num1 = 0;
    int num2 = 0;
    int result = 0;

    std::cout << "Welcome World!\n" ;

    std::cout << "Enter First Number: ";
    std::cin >> num1;

    std::cout << "Enter Second Number: ";
    std::cin >> num2;

    result = num1 + num2;

    std::cout << "Sum of two intergers is " << result <<std::endl;

    return 0;
}
