//
// Created by Xorum on 2/7/2023.
//

#ifndef PROIECT_0902_UNIVERSITY_H
#define PROIECT_0902_UNIVERSITY_H
#include "Faculty.h"
#include <string>
#include <vector>

using namespace std;

class University {
private:
    string codeUni;
    string nameUni;
    string status;
    vector <Faculty> faculties;
public:
    University(); //Empty constructor
    University(string code, string name, string status); //Constructor with variables
    ~University(); //Destructor

    const string &getCodeUni() const; //Get Function for the University code
    void setCodeUni(const string &codeUni); //Set Function for the University code
    const string &getNameUni() const; //Get Function for the University name
    void setNameUni(const string &nameUni); //Set Function for the University name
    const string &getStatus() const; //Get Function for the University status
    void setStatus(const string &status); //Set Function for the University status

    const vector<Faculty> &getListFaculties() const; //Get Function for the University list of faculties
    void setListFaculties(const Faculty &faculty); //1 Overloaded Set Function for the University list of faculties
    void setListFaculties(const vector<Faculty> &list); //2 Overloaded Set Function for the University list of faculties

    void updateFacultyList(Faculty &tempFac); //Funtion that updates a University list of Faculties
    void updateFaculty(int index, Faculty faculty); //Function that updates a University faculty info
    Faculty addFaculty(); //Function that adds a new Faculty in the university
    static void searchFaculty(vector <University> universities, int &i, int &j, bool &found); //Function that searches a Faculty in the University list of Faculties
    static void searchUniversity(vector <University> universities, int &i, bool &found); //Function that searches a University
};


#endif //PROIECT_0902_UNIVERSITY_H
