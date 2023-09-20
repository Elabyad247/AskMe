//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#include "../includes/Hospital.h"
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

doctor::doctor() {
  specialization = "";
}

void doctor::loadData() {
  ifstream file;
  file.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/doctors.txt");
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
    getline(s, specialization, ',');
    Hospital::doctorsList[id] = *this;
  }
  file.close();
}

void doctor::addPerson() {
  cout << "< ADD DOCTOR >" << endl;
  person::addPerson();
  cout << "Enter specialization: ";
  getline(cin >> ws, specialization);
  id = 1;
  if (!Hospital::doctorsList.empty()) {
    id = Hospital::doctorsList.rbegin()->first + 1;
  }
  Hospital::doctorsList[id] = *this;

  fstream file;
  file.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/doctors.txt", ios::app);
  file << id << "," << fName << "," << lName << "," << age << "," << gender << "," << phNumber << "," << specialization << endl;
  file.close();

  cout << endl << fName << " " << lName << " added successfully with ID: " << id << "\n";
}

void doctor::removePerson() {
  cout << "< REMOVE DOCTOR >" << endl;
  int rID;
  cout << "Enter ID: ";
  cin >> rID;
  if (Hospital::doctorsList.find(rID) != Hospital::doctorsList.end()) {
    *this = Hospital::doctorsList[rID];
    Hospital::doctorsList.erase(rID);
    string line;
    stringstream str;
    str << rID << "," << fName << "," << lName << "," << age << "," << gender << "," << phNumber << "," << specialization;
    getline(str, line);
    ifstream file;
    ofstream tempFile;
    file.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/doctors.txt");
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
    rename("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/doctors.txt", "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp2.txt");
    rename("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp.txt", "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/doctors.txt");
    rename("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp2.txt", "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/temp.txt");
    cout << "Doctor with id: " << rID << ", Name: " << this->getFullName() << " removed" << "\n";
  } else {
    cout << "No matching record found!" << "\n";
  }
}

void doctor::getDetails() {
  cout << "< GET DOCTOR DETAILS >" << endl;
  int dID;
  cout << "Enter ID: ";
  cin >> dID;
  if (Hospital::doctorsList.find(dID) != Hospital::doctorsList.end()) {
    *this = Hospital::doctorsList[dID];
    person::printDetails();
    cout << "Specialization: " << specialization << endl;
    cout << "\n";
  } else {
    cout << "No matching record found!" << endl;
  }
}

void doctor::printDetails() {
  person::printDetails();
  cout << "Specialization: " << specialization << endl;
  cout << "\n";
}