//
// Created by Xorum on 2/7/2023.
//

#ifndef PROIECT_0902_STUDENT_H
#define PROIECT_0902_STUDENT_H
#include <string>

using namespace std;

class Student {
private:
    string firstNameStud;
    string lastNameStud;
    string codeStudent;
    int year;
    double yearTax;
    double paidTax;
public:
    Student(); //Empty constructor
    ~Student(); //Destructor
    Student(string first, string last, string code, int year, double totalTax, double paidTax); //Constructor with variables

    const string &getFirstNameStud() const; //Get Function for the Student First Name
    void setFirstNameStud(const string &firstNameStud); //Set Function for the Student First Name
    const string &getLastNameStud() const; //Get Function for the Student Last Name
    void setLastNameStud(const string &lastNameStud); //Set Function for the Student Last Name
    const string &getCodeStudent() const; //Get Function for the Student code
    void setCodeStudent(const string &codeStudent); //Set Function for the Student code
    int getYear() const; //Get Function for the Student year
    void setYear(int year); //Set Function for the Student year
    double getYearTax() const; //Get Function for the Student year tax
    void setYearTax(double yearTax); //Set Function for the Student year tax
    double getPaidTax() const; //Get Function for the Student paid tax
    void setPaidTax(double paidTax); //Set Function for the Student paid tax
};

#endif //PROIECT_0902_STUDENT_H
