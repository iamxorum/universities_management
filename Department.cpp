//
// Created by Xorum on 2/7/2023.
//

#include "Department.h"

const string &Department::getCodeDepartment() const {
    return codeDepartment;
}

void Department::setCodeDepartment(const string &codeDepartment) {
    this->codeDepartment = codeDepartment;
}

Department::Department() {
    this->codeDepartment = "#####";
}

Department::Department(string code) {
    this->codeDepartment = code;
}

Department::~Department() {
}