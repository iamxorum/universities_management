//
// Created by Xorum on 2/7/2023.
//

#ifndef PROIECT_0902_FACULTY_H
#define PROIECT_0902_FACULTY_H
#include "Student.h"
#include "Department.h"
#include <string>
#include <vector>

using namespace std;

class Faculty{
private:
    string codeFaculty;
    string nameFaculty;
    int bachelorYears;
    int masterYears;
    int doctorateYears;
    double yearTax;
    string scholarship;
    vector <Student> students;
    vector <Department> departments;
public:
    Faculty(); //Empty constructor
    Faculty(string code, string name, int bach, int mas, int doc, double tax, string schol); //Constructor with variables
    ~Faculty(); //Destructor

    const string &getCodeFaculty() const; //Get Function for the Faculty code
    void setCodeFaculty(const string &codeFaculty); //Set Function for the Faculty code
    const string &getNameFaculty() const; //Get Function for the Faculty name
    void setNameFaculty(const string &nameFaculty); //Set Function for the Faculty name
    int getBachelorYears() const; //Get Function for the Faculty bachelor years
    void setBachelorYears(int bachelorYears); //Set Function for the Faculty bachelor years
    int getMasterYears() const; //Get Function for the Faculty master years
    void setMasterYears(int masterYears); //Set Function for the Faculty master years
    int getDoctorateYears() const; //Get Function for the Faculty doctorate years
    void setDoctorateYears(int doctorateYears); //Set Function for the Faculty doctorate years
    double getYearTax() const; //Get Function for the Faculty year tax
    void setYearTax(double yearTax); //Set Function for the Faculty year tax
    const vector<Student> &getStudents() const; //Get Function for the Faculty list of students
    void setStudents(const Student &studs); //1 Overloaded Set Function for the Faculty list of students
    void setStudents(const vector<Student> &studs); //2 OVerloaded Set Function for the Faculty list of students
    const vector<Department> &getDepartments() const; //Get Function for the Faculty list of depatments
    void setDepartments(const Department &deps); //Set Function for the Faculty list of departments
    const string &getScholarship() const; //Get Function for the Faculty scholarship
    void setScholarship(const string &scholarship); //Set Function for the Faculty scholarship

    Student createStudent(); //Function that creates a new student
    Department createDepartment(); //Function that creates a new department
    void addDepartment(Department department); //Function that adds a new student in a faculty
    void addStudent(Student student); //Function that adds a new department in a faculty

};


#endif //PROIECT_0902_FACULTY_H
