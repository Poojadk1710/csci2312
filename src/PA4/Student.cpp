/*********************************************************
* Summary: This file includes the implementation for the Student class (defined
* in Student.h).
*
* Author: Deeptimaan Banerjee
* Created: September 22, 2023
*
********************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Student.h"

Student::Student(int sid, std::string fName, std::string lName, std::string address, long phone, std::string grades, int count):
                sid{sid}, fName{fName}, lName{lName}, address{address}, phone{phone}, grades{grades}, count{count}
{
    // sid = sid;
    // fName = fName;
    // lName = lName;
    // address = address;
    // phone = phone;
    // grades = grades;
    // count = count;
};

int Student::getSID()
{
    return sid;
};

std::string Student::getFName()
{
    return fName;
};

std::string Student::getLName()
{
    return lName;
};

std::string Student::getAddress()
{
    return address;
};

long Student::getPhone()
{
    return phone;
};

int Student::getCount()
{
    return count;
}

void Student::setSID(int aSid)
{
    sid = aSid;
};

void Student::setFName(std::string aName)
{
    fName = aName;
};

void Student::setLName(std::string aName)
{
    lName = aName;
};

void Student::setAddress(std::string anAddr)
{
    address = anAddr;
};
void Student::setPhone(long aPhone)
{
    phone = aPhone;
};

std::string Student::getGrade(int location)
{
    /**
     * Returns the value of the ith grade, assuming that the grade attribute contains all the grades separated by a space.
     * The first grade will be in location 0, and if there are n grades, the last grade will be in position n-1.
     * There is no control with the given location. Unexpected results may be obtained.
     *
     * @param location The 0-indexed location of the grade.
     * @return A string with the value.
     */
    std::istringstream iss(grades);
    std::string value;
    int counter = 0;
    while (iss >> value)
    {
      if (counter++ == location)
      {
        return value;
      }
    }
};

void Student::addGrade(int aGrade)
{
    if (aGrade>=0 && aGrade<=100)
    {
        grades = grades + " " + std::to_string(aGrade);
        count+=1;
    }
};

std::string Student::computeLetterGrade(const int num_Grade)
{
    switch(num_Grade)
    {
        case 0 ... 60:
            return "F";
            break;
        case 61 ... 63:
            return "D-";
            break;
        case 64 ... 66:
            return "D";
            break;
        case 67 ... 69:
            return "D+";
            break;
        case 70 ... 73:
            return "C-";
            break;
        case 74 ... 76:
            return "C";
            break;
        case 77 ... 79:
            return "C+";
            break;
        case 80 ... 83:
            return "B-";
            break;
        case 84 ... 86:
            return "B";
            break;
        case 87 ... 89:
            return "B+";
            break;
        case 90 ... 93:
            return "A-";
            break;
        case 94 ... 100:
            return "A";
            break;
    }
};

std::string Student::currentLetterGrade()
{
    int sum = 0;
    std::istringstream iss(grades);
    std::string value;
    int counter = 0;
    while (iss >> value)
    {
      sum = sum + stoi(value);
      counter++;
    }
    return(computeLetterGrade(sum/counter));
};

void Student::listGrades()
{
    float sum = 0;
    float avg = 0;
    std::istringstream iss(grades);
    std::string value;
    std::cout << std::setfill('*') << std::setw(14) << "" << std::endl;
    std::cout << std::setfill(' ') << std::setw(3) << "GRD" << " " << std::setw(10) << "Cum.Avg." << std::endl;
    std::cout << std::setfill('*') << std::setw(14) << "" << std::endl;
    std::cout << std::fixed << std::showpoint;
    std::cout.precision(2);
    for (int counter = 1; iss >> value; counter++)
    {
        sum = sum + stoi(value);
        avg = sum/counter;
        std::cout << std::setfill(' ') << std::setw(3) << stoi(value) << " " << std::setw(10) << avg << std::endl;
    }
};