#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "University.h"
#include <unistd.h>
#include <direct.h>
#include <thread>
#include <chrono>
#include <cmath>

void show_progress_bar(int a, const std::string &message, char symbol){ // Function display progression bar
    string progress_bar;

    cout << message << "\n";

    int percentage = 1;
    do
    {
        srand(time(NULL));
        int progress_level = 1 + rand() % 15;
        progress_bar.insert(0, 1, symbol);
        cout << "\r {" << ceil(percentage) << '%' << "} " << progress_bar;
        this_thread::sleep_for(chrono::milliseconds(a));
        percentage += progress_level;
        if(percentage>=100){
            cout << "\r{100%} " << progress_bar <<  " | LOADING COMPLETED";
        }
    }while (percentage < 100);
}

void displaymenu(){ // Function display menu
    cout<<"\t\t\t\t\t=========================================================================== \n";
    cout<<"\t\t\t\t\t#\t\t\t  UNIVERSITY MANAGEMENT\t\t\t\t  #\n";
    cout<<"\t\t\t\t\t=========================================================================== \n";
    cout<<"\t\t\t\t\t# \t\t\t1.Add management records\t\t\t  #\n";
    cout<<"\t\t\t\t\t# \t\t2.Add new faculty to an existing university\t\t  #\n";
    cout<<"\t\t\t\t\t# \t\t3.Add new student to an existing faculty\t\t  #\n";
    cout<<"\t\t\t\t\t# \t\t4.Add new department to an existing faculty\t\t  #\n";
    cout<<"\t\t\t\t\t# \t5.Delete a student from a specific faculty, given the code\t  #\n";
    cout<<"\t\t\t\t\t# \t\t6.Search for a student from a specific faculty\t\t  #\n";
    cout<<"\t\t\t\t\t# \t\t\t7.Student payment collection\t\t\t  #\n";
    cout<<"\t\t\t\t\t# \t8.Display students who still have to pay from a certain faculty\t  #\n";
    cout<<"\t\t\t\t\t# \t   9.Calculate the amount collected for a certain faculty  \t  #\n";
    cout<<"\t\t\t\t\t# \t\t\t    10.SAVE records\n";
    cout<<"\t\t\t\t\t# \t\t\t    11.EXIT program\n";
    cout<<"\t\t\t\t\t=========================================================================== \n";
}

vector <University> loadFromFile(vector <University> A){ // Function load database from file
    int i,j, count=0;
    char linie[1000];
    char*p;
    bool found=false;

    //This while loop reads the file universities.txt and puts every line in the "linie" variable
    ifstream iter1("C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\universities.txt");
    while(iter1.getline(linie, 1000))
    {
        University temp1;
        p = strtok(linie, ","); //Delimiter ',' helps to break the line in parts and store the variables singularly
        temp1.setCodeUni(p);

        // Check if the code already exists in the vector
        bool codeExists = false;
        for (i = 0; i < A.size(); i++) {
            if (A[i].getCodeUni() == temp1.getCodeUni()) {
                codeExists = true;
                break;
            }
        }

        p = strtok(NULL, ",");
        temp1.setNameUni(p);

        // If the code exists, generate a new randomized code
        if (codeExists) {
            cout << endl << "---------------------------------------------" << endl;
            cout << "     The university's code of '" << temp1.getNameUni() <<"' already esists! I will proivde to give a new unique code!";
            int newCode;
            do {
                newCode = rand() % 10000;
                codeExists = false;
                for (i = 0; i < A.size(); i++) {
                    if (A[i].getCodeUni() == to_string(newCode)) {
                        codeExists = true;
                        break;
                    }
                }
            } while (codeExists);
            temp1.setCodeUni(to_string(newCode));
        }

        p = strtok(NULL, ",");
        temp1.setStatus(p);

        A.push_back(temp1);
    }
    iter1.close();
    //##################################################################################################################
    //This while loop reads the file faculties.txt and puts every line in the "linie" variable
    ifstream iter2("C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\faculties.txt");
    while(iter2.getline(linie, 1000))
    {
        Faculty temp2;
        p = strtok(linie, ","); //Delimiter ',' helps to break the line in parts and store the variables singularly
        for(i=0; i<A.size();i++){
            string nameUni = A[i].getNameUni();
            nameUni.erase(remove_if(nameUni.begin(), nameUni.end(), ::isspace), nameUni.end());

            string pStripped(p);
            pStripped.erase(remove_if(pStripped.begin(), pStripped.end(), ::isspace), pStripped.end());

            if (nameUni.compare(pStripped) == 0) {
                // Here I check if the first variable is the same, if yes, it means that I found The university in the
                // database and I can proceed to load the university's current faculty in the University's list of faculties
                found = true;
                break;
            }
            found = false;
        }
        if(found){
            p = strtok(NULL, ",");
            temp2.setCodeFaculty(p);

            // Check if the code is unique
            bool codeExists = false;
            for (const auto &uni : A) {
                for (const auto &fac : uni.getListFaculties()) {
                    if (temp2.getCodeFaculty() == fac.getCodeFaculty()) {
                        codeExists = true;
                        break;
                    }
                }
                if (codeExists) break;
            }

            p = strtok(NULL, ",");
            temp2.setNameFaculty(p);

            if (codeExists) {
                int newCode;
                cout << endl << "---------------------------------------------" << endl;
                cout << "     The faculty's code of '" << temp2.getNameFaculty() <<"' already esists! I will proivde to give a new unique code!";
                do {
                    newCode = rand() % 10000;
                    codeExists = false;
                    found = false;
                    for (const auto &uni : A) {
                        for (const auto &fac : uni.getListFaculties()) {
                            if ( fac.getCodeFaculty() == to_string(newCode)) {
                                codeExists = true;
                                break;
                            }
                        }
                        if (codeExists) break;
                    }
                } while (codeExists);
                temp2.setCodeFaculty(to_string(newCode));
            }

            p = strtok(NULL, ",");
            temp2.setBachelorYears(atof(p));

            p = strtok(NULL, ",");
            temp2.setMasterYears(atof(p));

            p = strtok(NULL, ",");
            temp2.setDoctorateYears(atof(p));

            p = strtok(NULL, ",");
            temp2.setYearTax(atof(p));

            p = strtok(NULL, ",");
            temp2.setScholarship(p);

            A[i].setListFaculties(temp2);
            count++;
        } else {
            cout << "Error! The University in the line nr. " << count+1 << " doesn't match in the database!" << endl;
            count++;
        }
    }
    iter2.close();
    //##################################################################################################################
    //This while loop reads the file departments.txt and puts every line in the "linie" variable
    count=0;
    string nameFac,pStripped;
    ifstream iter3("C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\departments.txt");
    while(iter3.getline(linie, 1000)){
        Department temp3;
        p = strtok(linie, ",");
        for(i=0; i<A.size();i++){

            string nameUni = A[i].getNameUni();
            nameUni.erase(remove_if(nameUni.begin(), nameUni.end(), ::isspace), nameUni.end());

            string pStripped(p);
            pStripped.erase(remove_if(pStripped.begin(), pStripped.end(), ::isspace), pStripped.end());

            if (nameUni.compare(pStripped) == 0) {
                // Here I check if the first variable is the same, if yes, it means that I found The university in the
                // database and I can proceed to access the university's current faculty in the University's list of faculties
                p = strtok(NULL, ",");
                vector <Faculty> tempFac = A[i].getListFaculties();
                for(j=0;j<tempFac.size();j++){
                    nameFac = tempFac[j].getNameFaculty();
                    nameFac.erase(remove_if(nameFac.begin(), nameFac.end(), ::isspace), nameFac.end());

                    string pStripped(p);
                    pStripped.erase(remove_if(pStripped.begin(), pStripped.end(), ::isspace), pStripped.end());
                    if(nameFac.compare(pStripped)==0) {
                        // Here I check if the first variable is the same, if yes, it means that I found The faculty in the
                        // database and I can proceed to load the faculty's current student in the Faculty's list of departments
                        found = true;
                        break;
                    }
                }
                break;
            }
            found = false;
        }
        vector <Faculty> list = A[i].getListFaculties();
        for (int j = 0; j < list.size(); j++) {
            Faculty tempFac = list[j];
            if (found) {
                Department temp3;
                p = strtok(NULL, ",");
                temp3.setCodeDepartment(p);
                tempFac.addDepartment(temp3);
                A[i].updateFaculty(j, tempFac);
                break;
            }
            if (j == list.size() - 1) {
                cout << "Error! The Faculty in the line nr. " << count+1 << " doesn't match in the database!" << endl;
            }
        }
    }
    iter3.close();
    //##################################################################################################################
    //This while loop reads the file departments.txt and puts every line in the "linie" variable
    count=0;
    ifstream iter4("C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\students.txt");
    while(iter4.getline(linie, 1000)){
        Student temp4;
        p = strtok(linie, ",");
        for(i=0; i<A.size();i++){
            string nameUni = A[i].getNameUni();
            nameUni.erase(remove_if(nameUni.begin(), nameUni.end(), ::isspace), nameUni.end());

            string pStripped(p);
            pStripped.erase(remove_if(pStripped.begin(), pStripped.end(), ::isspace), pStripped.end());

            if (nameUni.compare(pStripped) == 0) {
                // Here I check if the first variable is the same, if yes, it means that I found The university in the
                // database and I can proceed to access the university's current faculty in the University's list of faculties
                p = strtok(NULL, ",");
                vector <Faculty> tempFac = A[i].getListFaculties();
                for(j=0;j<tempFac.size();j++){
                    string nameFac = tempFac[j].getNameFaculty();
                    nameFac.erase(remove_if(nameFac.begin(), nameFac.end(), ::isspace), nameFac.end());

                    string pStripped(p);
                    pStripped.erase(remove_if(pStripped.begin(), pStripped.end(), ::isspace), pStripped.end());
                    if(nameFac.compare(pStripped)==0) {
                        // Here I check if the first variable is the same, if yes, it means that I found The faculty in the
                        // database and I can proceed to load the faculty's current student in the Faculty's list of students
                        found = true;
                        break;
                    }
                }
                break;
            }
            found = false;
        }
        vector <Faculty> list = A[i].getListFaculties();
        if (j < list.size()) {
            Faculty tempFac = list[j];
            if(found){
                p = strtok(NULL, ",");
                temp4.setFirstNameStud(p);

                p = strtok(NULL, ",");
                temp4.setLastNameStud(p);

                p = strtok(NULL, ",");
                temp4.setYear(atof(p));

                p = strtok(NULL, ",");
                temp4.setCodeStudent(p);

                p = strtok(NULL, ",");
                temp4.setYearTax(atof(p));

                p = strtok(NULL, ",");
                temp4.setPaidTax(atof(p));

                tempFac.addStudent(temp4);
                A[i].updateFaculty(j, tempFac);
                count++;
                list.clear();
            } else {
                cout << "Error! The Faculty in the line nr. " << count+1 << " doesn't match in the database!" << endl;
                count++;
            }
        }
    }
    iter4.close();

    return A;
}

int main() {
    vector <University> universities;
    int ans;
    while(1){
        displaymenu();
        cout << "################ | Enter your choice: >";
        cin >> ans;
        switch (ans) {
            case 1: {
                show_progress_bar(100, "Loading..." , '#');
                universities = loadFromFile(universities);
                cout << endl << "MANAGEMENT UPLOADED!" << endl;
                cout << endl;
                sleep(3);
                break;
            }
            case 2: {
                bool found = false;
                int i;
                University::searchUniversity(universities, i, found);
                if (found) {
                    Faculty tempFac = universities[i].addFaculty();
                    universities[i].updateFacultyList(tempFac);
                } else {
                    cout << "University not found." << endl;
                }
                cout << endl;
                break;
            }
            case 3: {
                bool found = false;
                int i, j;
                University::searchFaculty(universities,i,j,found);
                vector<Faculty> list = universities[i].getListFaculties();
                if (j < list.size()) {
                    Faculty tempFac = list[j];

                    if (found) {
                        Student temp = tempFac.createStudent();
                        tempFac.addStudent(temp);
                        universities[i].updateFaculty(j, tempFac);
                    } else {
                        cout << "Faculty not found." << endl;
                    }
                }
                list.clear();
                cout << endl;
                break;
            }
            case 4: {
                bool found = false;
                int i, j;
                University::searchFaculty(universities,i,j,found);
                vector<Faculty> list = universities[i].getListFaculties();
                if (j < list.size()) {
                    Faculty tempFac = list[j];

                    if (found) {
                        Department temp = tempFac.createDepartment();

                        tempFac.setDepartments(temp);
                        universities[i].updateFaculty(j, tempFac);
                    } else {
                        cout << "Faculty not found." << endl;
                    }
                }
                list.clear();
                cout << endl;
                break;
            }
            case 5: {
                bool found = false;
                int i, j;
                University::searchFaculty(universities,i,j,found);
                string codeStudent;
                cout << "Please enter the student ID code of the student you wish to search for:";
                getline(cin, codeStudent);
                vector<Faculty> list = universities[i].getListFaculties();
                if (j < list.size()) {
                    Faculty tempFac = list[j];
                    vector<Student> students = tempFac.getStudents();
                    for(int k = 0; k < students.size(); k++) {
                        if (students[k].getCodeStudent() == codeStudent) {
                            students.erase(students.begin() + k);
                            break;
                        }
                    }
                    tempFac.setStudents(students);
                    list[j] = tempFac;
                    universities[i].setListFaculties(list);
                }
                list.clear();
                cout << endl;
                break;
            }
            case 6: {
                bool found = false;
                bool found1 = false;
                int i, j;
                University::searchFaculty(universities,i,j,found);
                string codeStudent;
                cout << "Please enter the student ID code of the student you wish to search for:";
                getline(cin, codeStudent);
                vector<Faculty> list = universities[i].getListFaculties();
                if (j < list.size()) {
                    Faculty tempFac = list[j];
                    vector<Student> students = tempFac.getStudents();
                    for(int k = 0; k < students.size(); k++) {
                        if (students[k].getCodeStudent() == codeStudent) {
                            found1=true;
                            cout << "-------------------------------------" << endl;
                            cout << "The student was found: " << students[k].getFirstNameStud() << " " << students[k].getLastNameStud() << endl;
                            cout << "-------------------------------------" << endl;
                            break;
                        }
                    }
                    if(!found1){
                        cout << "-------------------------------------" << endl;
                        cout << "The student was not found." << endl;
                        cout << "-------------------------------------" << endl;
                    }
                }
                list.clear();
                cout << endl;
                break;
            }
            case 7: {
                bool found = false;
                bool found1 = false;
                int i, j;
                University::searchFaculty(universities,i,j,found);
                string codeStudent;
                cout << "Please enter the student ID code of the student you wish to search for:";
                getline(cin, codeStudent);
                vector<Faculty> list = universities[i].getListFaculties();
                if (j < list.size()) {
                    Faculty tempFac = list[j];
                    vector<Student> students = tempFac.getStudents();
                    for(int k = 0; k < students.size(); k++) {
                        if (students[k].getCodeStudent() == codeStudent) {
                            found1 = true;
                            if(students[k].getPaidTax()<students[k].getYearTax()){
                                double t;
                                cout << "Please enter the amount you are paying. {You still have to pay: " << students[k].getYearTax()-students[k].getPaidTax() << " euro}:";
                                cin >> t;
                                if(students[k].getPaidTax()+t>=students[k].getYearTax()){
                                    if(students[k].getPaidTax()+t==students[k].getYearTax()){
                                        cout << "CONGRATULATIONS! The student " << students[k].getLastNameStud() << " " << students[k].getFirstNameStud() << " has paid all the taxes!" << endl;
                                        students[k].setPaidTax(students[k].getYearTax());
                                        break;
                                    }
                                    cout << "CONGRATULATIONS! The student " << students[k].getLastNameStud() << " " << students[k].getFirstNameStud() << " has paid all the taxes! You sent more money than necessary; We sent you back " << students[k].getPaidTax()+t-students[k].getYearTax() << " euro." << endl;
                                    students[k].setPaidTax(students[k].getYearTax());
                                } else {
                                    students[k].setPaidTax(students[k].getPaidTax()+t);
                                    cout << "CONGRATULATIONS! The payment was successful; You decreased the remainder tax to pay: " << students[k].getYearTax()-students[k].getPaidTax() << " euro" << endl;
                                }
                            } else {
                                cout << "The student " << students[k].getLastNameStud() << " " << students[k].getFirstNameStud() << " has already fully paid the fee." << endl;
                            }
                            break;
                        }
                    }
                    if(!found1){
                        cout << "-------------------------------------" << endl;
                        cout << "The student was not found." << endl;
                        cout << "-------------------------------------" << endl;
                    }
                    tempFac.setStudents(students);
                    list[j] = tempFac;
                    universities[i].setListFaculties(list);
                }
                list.clear();
                cout << endl;
                break;
            }
            case 8: {
                bool found = false;
                int i, j, count = 0;
                University::searchFaculty(universities,i,j,found);
                vector<Faculty> list = universities[i].getListFaculties();
                if (j < list.size()) {
                    Faculty tempFac = list[j];
                    vector<Student> students = tempFac.getStudents();
                    cout << "The students of '" << tempFac.getNameFaculty() << "' from the university '" << universities[i].getNameUni() << "' who still have to fully pay the annual fee are the following: " << endl;
                    for(int k = 0; k < students.size(); k++) {
                        if(students[k].getPaidTax()<students[k].getYearTax()){
                            count++;
                            cout << "\t\t The student " << students[k].getCodeStudent() << ": has to pay " << students[k].getYearTax()-students[k].getPaidTax() << " euro;" << endl;
                        }
                    }
                    if(count==0){
                        cout << "\t\tAll students of the faculty have paid the interim fee;" << endl;
                    }
                    count == 0;
                }
                list.clear();
                cout << endl;
                break;
            }
            case 9: {
                bool found = false;
                int i, j;
                double total = 0;
                University::searchFaculty(universities,i,j,found);
                vector<Faculty> list = universities[i].getListFaculties();
                if (j < list.size()) {
                    Faculty tempFac = list[j];
                    vector<Student> students = tempFac.getStudents();
                    for(int k = 0; k < students.size(); k++) {
                        if(students[k].getPaidTax()>0){
                            total = total + students[k].getPaidTax();
                        }
                    }
                    cout << "The faculty " << tempFac.getNameFaculty() << " from the university '" << universities[i].getNameUni() << "' has received: " << total << " euro;" << endl;
                }
                list.clear();
                cout << endl;
                break;
            }
            case 10: {
                string uniPath,facPath;
                char* backs = "\\";
                char* txt = ".txt";
                char* genPath = "C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\Universities\\";
                ofstream fout2("C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\students.txt");
                ofstream fout3("C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\departments.txt");
                ofstream fout4("C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\universities.txt");
                ofstream fout5("C:\\Users\\4ndr3\\Desktop\\Facultate\\POO\\Proiect_0902\\faculties.txt");
                mkdir(genPath);
                int i,j;

                for(int k = 0; k < universities.size(); k++) {
                    fout4 << universities[k].getCodeUni() << "," << universities[k].getNameUni() << "," << universities[k].getStatus() << endl;
                }
                for (i = 0; i < universities.size(); i++) {
                    uniPath = universities[i].getNameUni();
                    char cstr[1024]; // allocate memory for the character array
                    strcpy(cstr, uniPath.c_str());
                    char fullPath[1024]; // allocate memory for the full path
                    strcpy(fullPath, genPath); // copy the `genPath` string into `fullPath`
                    strcat(fullPath, cstr);
                    strcat(fullPath, backs);
                    mkdir(fullPath);
                    vector<Faculty> tempFac = universities[i].getListFaculties();
                    for(int k = 0; k < tempFac.size(); k++) {
                        fout5 << universities[i].getNameUni() << "," << tempFac[k].getCodeFaculty() << "," << tempFac[k].getNameFaculty() << "," << tempFac[k].getBachelorYears() << "," << tempFac[k].getMasterYears() << "," << tempFac[k].getDoctorateYears() << "," << tempFac[k].getYearTax() << "," << tempFac[k].getScholarship() << endl;
                    }
                    for (j = 0; j < tempFac.size(); j++) {
                        char currentPath[1024];
                        strcpy(currentPath, fullPath); // copy the `genPath` string into `fullPath`
                        facPath = tempFac[j].getNameFaculty();
                        strcpy(cstr, facPath.c_str());
                        strcat(currentPath, cstr);
                        strcat(currentPath, txt);
                        ofstream fout(currentPath);
                        vector<Faculty> list = universities[i].getListFaculties();
                        Faculty tempFac = list[j];
                        vector<Student> students = tempFac.getStudents();
                        vector<Department> departments = tempFac.getDepartments();
                        fout << "\t\t\t\t\t\t\t\t\tSTUDENTS" << endl;
                        fout << "###################################################################################\n";
                        for(int k = 0; k < students.size(); k++) {
                            fout << "Student " << k+1 << endl;
                            fout << "\t\tCode Student: " << students[k].getCodeStudent() << endl;
                            fout << "\t\tStudent: " << students[k].getLastNameStud() << " " << students[k].getFirstNameStud() << endl;
                            fout << "\t\tYear: " << students[k].getYear() << endl;
                            fout << "\t\tPaid Taxes: " << students[k].getPaidTax() << " | Total Taxes: " << students[k].getYearTax() << " | Remainder: " << students[k].getYearTax()-students[k].getPaidTax() << endl;
                            fout << "-----------------------------------------------------------------------------------\n";
                            fout2 << uniPath << "," << facPath << "," << students[k].getFirstNameStud() << "," << students[k].getLastNameStud() << "," << students[k].getYear() << "," << students[k].getCodeStudent() << "," << students[k].getYearTax() << "," << students[k].getPaidTax() << endl;
                        }
                        fout << "\t\t\t\t\t\t\t\t\tDEPARTMENTS" << endl;
                        fout << "###################################################################################\n";
                        for(int k = 0; k < departments.size(); k++) {
                            fout << "Department " << k+1 << endl;
                            fout << "\t\tCode Department: " << departments[k].getCodeDepartment() << endl;
                            fout << "-----------------------------------------------------------------------------------\n";
                            fout3 << uniPath << "," << facPath << "," << departments[k].getCodeDepartment() << endl;
                        }
                        fout.close();
                    }
                }
                fout2.close();
                fout3.close();
                fout4.close();
                fout5.close();
                cout << endl;
                break;
                }
            case 11: {
                cout << "Thank You and have a Nice day!" << endl;
                sleep(3);
                exit(0);
            }
        }
    }
    return 0;
}
