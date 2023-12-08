/*********************************************************
* Summary: This file includes the implementation for the function prototypes (defined
* in functions.h).
*
* Author: Deeptimaan Banerjee
* Created: September 27, 2023
*
********************************************************/

#include <iostream>
#include <string>
#include "function.h"

bool isEven(int number){
    // Test if number is even or not by checking the remainder when number is divided by 2
    if (number % 2 == 0){
        return true;
    }
    return false;
}

bool isPrime(int number){
    // If number entered is less than or equal to 1 then it is not prime
    if (number <= 1){
        return false;
    }
    // If number is divisible by any number from 2 to half of its value then it is not prime
    for (int i = 2; i <= number / 2; i++){
        if (number % i == 0){
            return false;
        }
    }
    return true;
}

int intPower(unsigned int base, int exponent){
    int product = 1;
    // Iteratively multiply product value with base for the number of times of the exponent value
    for (int i = 1; i <= exponent; i++){
        product = product * base;
    }
    return product;
}

int recPower(unsigned int base, int exponent){
    // When exponent reaches 0
    if (exponent == 0){
        return 1;
    }
    // If base entered is 0 then return 0
    if (base == 0){
        return 0;
    }
    // For any value of base entered greater than 0
    return base * recPower(base, exponent - 1);
}

void printReversed(int number){
    int rem = 0;
    int rev = 0;
    // Variable rev (reverse) will store the number in reverse
    while(number != 0){
        rem = number % 10;
        // Update rev by multiplying rev with 10 and then add remainder to reverse the number
        rev = (rev * 10) + rem;
        // Update number by dividing it with 10
        number = number / 10;
    }
    std::cout << rev;
}

void recPrintReversed(int number){
    // print number when base condition is reached
    if (number < 10) {
        std::cout << number;
        return;
    }
    // Printing Number in reverse
    else{
      std::cout << number % 10;
      recPrintReversed(number / 10);
    }
}

int maxValue(){
    int number = 0;
    std::cin >> number;
    // If number equal to sentinel input then return number
    if (number == -1){
        return 0;
    }
    // Initialize greatest with the max value recursively
    int greatest = maxValue();
    if (number >= greatest){
        // Return number variable if it is greater than greatest variable
        return number;
    }
    return greatest;
}