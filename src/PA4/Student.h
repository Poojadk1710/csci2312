#ifndef STUDENT_H
#define STUDENT_H
//Student.h below. Do no write code above this line
#include <string>


class Student
{
private:
    int sid;
    std::string fName;
    std::string lName;
    std::string address;
    long phone;
    std::string grades;
    int count;

public:
    explicit Student(int sid, std::string fName, std::string LName, std::string address, long phone, std::string grades, int count);

    int getSID();
    std::string getFName();
    std::string getLName();
    std::string getAddress();
    long getPhone();
    int getCount();

    void setSID(int sid);
    void setFName(std::string aFName);
    void setLName(std::string aLName);
    void setAddress(std::string anAddr);
    void setPhone(long aPhone);

    std::string getGrade(int location);
    void addGrade(int aGrade);
    std::string computeLetterGrade(const int);
    std::string currentLetterGrade();
    void listGrades();
};

//Student.h above. Do no write code below this line
#endif
