//
// Created by Xorum on 2/7/2023.
//

#include <iostream>
#include "Faculty.h"

using namespace std;

const string &Faculty::getCodeFaculty() const {
    return codeFaculty;
}

void Faculty::setCodeFaculty(const string &codeFaculty) {
    this->codeFaculty = codeFaculty;
}

const string &Faculty::getNameFaculty() const {
    return nameFaculty;
}

void Faculty::setNameFaculty(const string &nameFaculty) {
    this->nameFaculty = nameFaculty;
}

int Faculty::getBachelorYears() const {
    return bachelorYears;
}

void Faculty::setBachelorYears(int bachelorYears) {
    this->bachelorYears = bachelorYears;
}

int Faculty::getMasterYears() const {
    return masterYears;
}

void Faculty::setMasterYears(int masterYears) {
    this->masterYears = masterYears;
}

int Faculty::getDoctorateYears() const {
    return doctorateYears;
}

void Faculty::setDoctorateYears(int doctorateYears) {
    this->doctorateYears = doctorateYears;
}

double Faculty::getYearTax() const {
    return yearTax;
}

void Faculty::setYearTax(double yearTax) {
    this->yearTax = yearTax;
}

const vector<Student> &Faculty::getStudents() const {
    return students;
}

void Faculty::setStudents(const Student &studs) {
    students.push_back(studs);
}

void Faculty::setStudents(const vector<Student> &studs) {
    this->students = studs;
}

const vector<Department> &Faculty::getDepartments() const {
    return departments;
}

void Faculty::setDepartments(const Department &deps) {
    departments.push_back(deps);
}

Faculty::Faculty() {
    this->codeFaculty = "###";
    this->nameFaculty = "###";
    this->bachelorYears = 0;
    this->masterYears = 0;
    this->doctorateYears = 0;
    this->yearTax = 0;
    this->scholarship = false;
}

Faculty::Faculty(string code, string name, int bach, int mas, int doc, double tax, string schol) {
    this->codeFaculty = code;
    this->nameFaculty = name;
    this->bachelorYears = bach;
    this->masterYears = mas;
    this->doctorateYears = doc;
    this->yearTax = tax;
    this->scholarship = schol;
}

Faculty::~Faculty() {
    this->students.clear();
}

const string &Faculty::getScholarship() const {
    return scholarship;
}

void Faculty::setScholarship(const string &scholarship) {
    this->scholarship = scholarship;
}

Student Faculty::createStudent()  {
    Student newStudent;
    string first, last, code;
    int year;
    double totalTax, paidTax;
    cout << "Add the new student" << endl;
    cout << "********* First name:";
    getline(cin,first);
    cin.clear();
    newStudent.setFirstNameStud(first);
    cout << "********* Last name:";
    getline(cin,last);
    cin.clear();
    newStudent.setLastNameStud(last);
    cout << "********* Code Student:";
    getline(cin,code);
    cin.clear();
    newStudent.setCodeStudent(code);
    cout << "********* Year:";
    cin >> year;
    newStudent.setYear(year);
    cout << "********* Tax:";
    cin >> totalTax;
    newStudent.setYearTax(totalTax);
    cout << "********* Paid Tax:";
    cin >> paidTax;
    newStudent.setPaidTax(paidTax);
    return newStudent;
}

Department Faculty::createDepartment() {
    Department newDepartment;
    string code;
    cout << "Add the new department" << endl;
    cout << "********* Code department:";
    getline(cin,code);
    cin.clear();
    newDepartment.setCodeDepartment(code);
    return newDepartment;
}

void Faculty::addDepartment(Department department) {
    departments.push_back(department);
}

void Faculty::addStudent(Student s) {
    students.push_back(s);
}
