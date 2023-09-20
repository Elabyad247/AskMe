//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#include "../includes/Hospital.h"
#include "../includes/patient.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

static int ToInt(const string &str) {
  istringstream iss(str);
  int num;
  iss >> num;
  return num;
}

patient::patient() {
  sickness = "";
}

void patient::loadData() {
  ifstream file;
  file.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/patients.txt");
  string temp;
  while (getline(file >> ws, temp)) {
    stringstream s(temp);
    string sID;
    getline(s, sID, ',');
    id = ToInt(sID);
    getline(s, fName, ',');
    getline(s, lName, ',');
    string sAge;
    getline(s, sAge, ',');
    age = ToInt(sAge);
    getline(s, gender, ',');
    getline(s, phNumber, ',');
    getline(s, sickness, ',');
    Hospital::patientsList[id] = *this;
  }
  file.close();
}

void patient::addPerson() {
  cout << "< ADD PATIENT >" << endl;
  person::addPerson();
  cout << "Enter sickness: ";
  getline(cin >> ws, sickness);
  id = 1;
  if (!Hospital::patientsList.empty()) {
    id = Hospital::patientsList.rbegin()->first + 1;
  }
  Hospital::patientsList[id] = *this;

  fstream file;
  file.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/patients.txt", ios::app);
  file << id << "," << fName << "," << lName << "," << age << "," << gender << "," << phNumber << "," << sickness << endl;
  file.close();

  cout << endl << fName << " " << lName << " added successfully with ID: " << id << endl;
}

void patient::removePerson() {
  cout << "< REMOVE PATIENT >" << endl;
  int rID;
  cout << "Enter ID: ";
  cin >> rID;
  if (Hospital::patientsList.find(rID) != Hospital::patientsList.end()) {
    *this = Hospital::patientsList[rID];
    Hospital::patientsList.erase(rID);
    string line;
    stringstream str;
    str << rID << "," << fName << "," << lName << "," << age << "," << gender << "," << phNumber << "," << sickness;
    getline(str, line);
    ifstream file;
    ofstream tempFile;
    file.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/patients.txt");
    tempFile.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp.txt");
    string temp;
    while (getline(file, temp)) {
      if (temp == line) {
        continue;
      }
      tempFile << temp << endl;
    }
    file.close();
    tempFile.close();
    rename("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/patients.txt", "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp2.txt");
    rename("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp.txt", "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/patients.txt");
    rename("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp2.txt", "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp.txt");
    cout << "Patient with id: " << rID << ", Name: " << this->getFullName() << " removed" << endl;
  } else {
    cout << "No matching record found!" << endl;
  }
}

void patient::getDetails() {
  cout << "< GET PATIENT DETAILS >" << endl;
  int pID;
  cout << "Enter ID: ";
  cin >> pID;
  if (Hospital::patientsList.find(pID) != Hospital::patientsList.end()) {
    *this = Hospital::patientsList[pID];
    person::printDetails();
    cout << "Sickness: " << sickness << endl;
  } else {
    cout << "No matching record found!" << endl;
  }
}

void patient::printDetails() {
  person::printDetails();
  cout << "Sickness: " << sickness << endl;
  cout << "\n";
}

string patient::getSickness() {
  return sickness;
}