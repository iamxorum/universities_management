//
// Created by Xorum on 2/7/2023.
//

#ifndef PROIECT_0902_DEPARTMENT_H
#define PROIECT_0902_DEPARTMENT_H
#include <string>

using namespace std;

class Department {
private:
    string codeDepartment;
public:
    Department(); //Empty constructor
    Department(string code); //Constructor with variables
    ~Department(); //Destructor

    const string &getCodeDepartment() const; //Get Function for the Department code
    void setCodeDepartment(const string &codeDepartment); //Set Function for the Department code
};


#endif //PROIECT_0902_DEPARTMENT_H
