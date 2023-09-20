//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#include "../includes/appointment.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

static int ToInt(const string &str) {
  istringstream iss(str);
  int num;
  iss >> num;
  return num;
}

appointment::appointment() {
  id = -1;
  hour = -1;
  date = "DD-MM-YYYY";
  aDoctor.id = -1;
  aPatient.id = -1;
}

void appointment::loadData() {
  ifstream file;
  file.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/appointments.txt");
  string temp;
  while (getline(file >> ws, temp)) {
    stringstream s(temp);
    string aID;
    getline(s, aID, ',');
    id = ToInt(aID);
    string aHour;
    getline(s, aHour, ',');
    aHour = ToInt(aHour);
    getline(s, date, ',');
    string docID;
    getline(s, docID, ',');
    int dID = ToInt(docID);
    aDoctor = Hospital::doctorsList[dID];
    string patID;
    getline(s, patID, ',');
    int pID = ToInt(patID);
    aPatient = Hospital::patientsList[pID];
    Hospital::appointmentsList[id] = *this;
  }
  file.close();
}

void appointment::getDetails() {
  cout << "< GET APPOINTMENT DETAILS >" << endl;
  int aID;
  cout << "Enter ID: ";
  cin >> aID;
  if (Hospital::appointmentsList.find(aID) != Hospital::appointmentsList.end()) {
    *this = Hospital::appointmentsList[aID];
    appointment::printDetails();
  } else {
    cout << "No matching record found!" << endl;
  }
}

void appointment::printDetails() {
  cout << "Appointment ID: " << id << endl;
  cout << "Appointment Date: " << hour << " , " << date << endl;
  cout << "Doctor's Name: " << aDoctor.getFullName() << endl;
  cout << "Patient's Name: " << aPatient.getFullName() << endl;
  cout << "\n";
}

void appointment::book() {
  cout << "Search for the patient: ";
  char choice = 'Y';
  while (choice == 'Y') {
    aPatient.getDetails();
    choice = 'S';
    if (aPatient.id == -1) {
      cout << "Try again? (Enter Y for Yes, N for No): ";
      cin >> choice;
      while (choice != 'Y' && choice != 'N') {
        cout << "Y or N?: ";
        cin >> choice;
      }
    }
  }
  if (choice == 'N') {
    return;
  }
  cout << "\n";
  cout << "Search for the doctor: ";
  choice = 'Y';
  while (choice == 'Y') {
    aDoctor.getDetails();
    choice = 'K';
    if (aDoctor.id == -1) {
      cout << "Try again? (Enter Y for Yes, N for No): ";
      cin >> choice;
      while (choice != 'Y' && choice != 'N') {
        cout << "Y or N?: ";
        cin >> choice;
      }
    }
  }
  if (choice == 'N') {
    return;
  }
  cout << "Enter date of appointment: ";
  getline(cin >> ws, date);

  cout << "Enter hour of appointment: ";
  cin >> hour;

  id = 1;
  if (!Hospital::appointmentsList.empty()) {
    id = Hospital::appointmentsList.rbegin()->first + 1;
  }
  Hospital::appointmentsList[id] = *this;

  fstream file;
  file.open("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Hospital/data/appointments.txt", ios::app);
  file << id << "," << hour << "," << date << "," << aDoctor.id << "," << aPatient.id << endl;
  file.close();

  cout << "Appointment of patient " + aPatient.getFullName() + " with doctor " << aDoctor.getFullName() << " booked successfully!\n";
  printDetails();
  cout << "\n";
}