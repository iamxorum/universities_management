//
// Created by Xorum on 2/7/2023.
//

#include "Student.h"

const string &Student::getFirstNameStud() const {
    return firstNameStud;
}

void Student::setFirstNameStud(const string &firstNameStud) {
    Student::firstNameStud = firstNameStud;
}

const string &Student::getLastNameStud() const {
    return lastNameStud;
}

void Student::setLastNameStud(const string &lastNameStud) {
    Student::lastNameStud = lastNameStud;
}

const string &Student::getCodeStudent() const {
    return codeStudent;
}

void Student::setCodeStudent(const string &codeStudent) {
    Student::codeStudent = codeStudent;
}

int Student::getYear() const {
    return year;
}

void Student::setYear(int year) {
    Student::year = year;
}

double Student::getYearTax() const {
    return yearTax;
}

void Student::setYearTax(double yearTax) {
    Student::yearTax = yearTax;
}

double Student::getPaidTax() const {
    return paidTax;
}

void Student::setPaidTax(double paidTax) {
    Student::paidTax = paidTax;
}

Student::Student() {
    this->firstNameStud = "###";
    this->lastNameStud = "###";
    this->codeStudent = "###";
    this->year = 0;
    this->yearTax = 0.0;
    this->paidTax = 0.0;
}

Student::Student(string first, string last, string code, int year, double totalTax, double paidTax) {
    this->firstNameStud = first;
    this->lastNameStud = last;
    this->codeStudent = code;
    this->year = year;
    this->yearTax = totalTax;
    this->paidTax = paidTax;
}

Student::~Student() {}