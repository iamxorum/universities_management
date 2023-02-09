//
// Created by Xorum on 2/7/2023.
//

#include "University.h"
#include <algorithm>
#include <iostream>
#include <limits>

const string &University::getCodeUni() const {
    return codeUni;
}

void University::setCodeUni(const string &codeUni) {
    this->codeUni = codeUni;
}

const string &University::getNameUni() const {
    return nameUni;
}

void University::setNameUni(const string &nameUni) {
    this->nameUni = nameUni;
}

const string &University::getStatus() const {
    return status;
}

void University::setStatus(const string &status) {
    this->status = status;
}

University::University() {
    this->codeUni = "####";
    this->nameUni = "####";
    this->status = "####";
}

University::University(string code, string name, string status) {
    this->codeUni = code;
    this->nameUni = name;
    this->status = status;
}

University::~University() {
    this->faculties.clear();
}

void University::setListFaculties(const Faculty &faculty) {
    faculties.push_back(faculty);
}

void University::setListFaculties(const vector<Faculty> &list) {
    this->faculties = list;
}

const vector<Faculty> &University::getListFaculties() const {
    return faculties;
}

void University::updateFacultyList(Faculty &tempFac) {
    for (int i = 0; i < faculties.size(); i++) {
        if (faculties[i].getCodeFaculty() == tempFac.getCodeFaculty()) {
            faculties[i] = tempFac;
            break;
        }
    }
}

void University::updateFaculty(int index, Faculty faculty) {
    vector <Faculty> list = this->getListFaculties();
    if (index >= 0 && index < list.size()) {
        list[index] = faculty;
        this->setListFaculties(list);
    } else {
        cout << "Error! The index is out of range!" << endl;
    }
}

Faculty University::addFaculty() {
    string code, name,scholarship;
    int bachelorYears, masterYears, doctorateYears;
    double yearTax;
    cout << "Add the new faculty" << endl;
    cout << "********* Code faculty: ";
    cin.clear();
    getline(cin, code);
    cout << "********* Name faculty: ";
    cin.clear();
    getline(cin, name);
    cout << "********* Bachelor years: ";
    cin >> bachelorYears;
    cout << "********* Master years: ";
    cin >> masterYears;
    cout << "********* Doctorate years: ";
    cin >> doctorateYears;
    cout << "********* Year tax: ";
    cin >> yearTax;
    cin.clear();
    cout << "********* Scolarhip {DA/NU}: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, scholarship);

    Faculty newFaculty(code,name,bachelorYears,masterYears,doctorateYears,yearTax,scholarship);
    faculties.push_back(newFaculty);
    return newFaculty;
}

void University::searchFaculty(vector <University> universities, int &i, int &j, bool &found){
    string uniName, facultyName;
    cout << endl;
    cout << "######################################################" << endl;
    cout << "\t\t Universities Available" << endl;
    for(int i=0;i<universities.size();i++){
        cout << "\t" << i+1 << ". " << universities[i].getNameUni() << ":" << endl;
        vector<Faculty> T = universities[i].getListFaculties();
        for(int j=0; j<T.size();j++){
            cout << "\t\t" << i+1 << "." << j+1 << ": "<< T[j].getNameFaculty() << endl;
        }
        cout << endl;
    }
    cout << "######################################################" << endl;
    cout << "Please enter the full name of the university (e.g. Titu Maiorescu University) | {Check the list above}:";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, uniName);
    cin.clear();
    cout << "Please enter the full name of the faculty (e.g. Facultatea de Informatica) | {Check the list above}:";
    getline(cin, facultyName);
    for (i = 0; i < universities.size(); i++) {
        string nameUni = universities[i].getNameUni();
        nameUni.erase(remove_if(nameUni.begin(), nameUni.end(), ::isspace), nameUni.end());

        string pStripped(uniName);
        pStripped.erase(remove_if(pStripped.begin(), pStripped.end(), ::isspace), pStripped.end());

        if (nameUni.compare(pStripped) == 0) {
            vector<Faculty> tempFac = universities[i].getListFaculties();
            for (j = 0; j < tempFac.size(); j++) {
                string nameFac = tempFac[j].getNameFaculty();
                nameFac.erase(remove_if(nameFac.begin(), nameFac.end(), ::isspace), nameFac.end());

                string pStripped(facultyName);
                pStripped.erase(remove_if(pStripped.begin(), pStripped.end(), ::isspace), pStripped.end());
                if (nameFac.compare(pStripped) == 0) {
                    found = true;
                    break;
                }
            }
            break;
        }
        found = false;
    }
}

void University::searchUniversity(vector <University> universities, int &i, bool &found){
    string uniName;
    cout << endl;
    cout << "######################################################" << endl;
    cout << "\t\t Universities Available" << endl;
    for(int i=0;i<universities.size();i++){
        cout << "\t" << i+1 << ". " << universities[i].getNameUni() << ":" << endl;
        vector<Faculty> T = universities[i].getListFaculties();
        for(int j=0; j<T.size();j++){
            cout << "\t\t" << i+1 << "." << j+1 << ": "<< T[j].getNameFaculty() << endl;
        }
        cout << endl;
    }
    cout << "######################################################" << endl;
    cout << "Please enter the full name of the university (e.g. Titu Maiorescu University) | {Check the list above}:";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, uniName);
    cin.clear();
    for (i = 0; i < universities.size(); i++) {
        string nameUni = universities[i].getNameUni();
        nameUni.erase(remove_if(nameUni.begin(), nameUni.end(), ::isspace), nameUni.end());

        string pStripped(uniName);
        pStripped.erase(remove_if(pStripped.begin(), pStripped.end(), ::isspace), pStripped.end());

        if (nameUni.compare(pStripped) == 0) {
            found = true;
            break;
        }
        found = false;
    }
}