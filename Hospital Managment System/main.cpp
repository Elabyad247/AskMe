//
// Created by Saifaldin Elabyad on 18/09/2023.
//
#include <iostream>
#include <string>
using namespace std;

void showMainMenu();
void showDoctorsMenu();
void showPatientsMenu();
void showAppointmentsMenu();

void showPatientsMenu() {
  cout << "< PATIENTS SECTION >" << endl;
  cout << "\t" << "01: Add Patient" << endl;
  cout << "\t" << "02: Remove Patient" << endl;
  cout << "\t" << "03: Get Patient Details" << endl;
  cout << "\t" << "04: Show All Patients" << endl;
  cout << "\t" << "-1: Back" << endl;

  int operationNumber;
  do {
    cout << "Enter operation number: ";
    cin >> operationNumber;
    if (operationNumber > 4 || operationNumber < -1 || operationNumber == 0) {
      cout << "Invalid operation number!" << endl;
    }
  } while (operationNumber > 4 || operationNumber < -1 || operationNumber == 0);
  cout << endl;
  if (operationNumber == 1) {

  } else if (operationNumber == 2) {

  } else if (operationNumber == 3) {

  } else if (operationNumber == 4) {

  } else if (operationNumber == -1) {
    cout << endl;
    showMainMenu();
  }
}

void showDoctorsMenu() {
  cout << "< DOCTORS SECTION >" << endl;
  cout << "\t" << "01: Add Doctor" << endl;
  cout << "\t" << "02: Remove Doctor" << endl;
  cout << "\t" << "03: Get Doctor Details" << endl;
  cout << "\t" << "04: Show All Doctors" << endl;
  cout << "\t" << "-1: Back" << endl;

  int operationNumber;
  do {
    cout << "Enter operation number: ";
    cin >> operationNumber;
    if (operationNumber > 4 || operationNumber < -1 || operationNumber == 0) {
      cout << "Invalid operation number!" << endl;
    }
  } while (operationNumber > 4 || operationNumber < -1 || operationNumber == 0);
  cout << endl;
  if (operationNumber == 1) {

  } else if (operationNumber == 2) {

  } else if (operationNumber == 3) {

  } else if (operationNumber == 4) {

  } else if (operationNumber == -1) {
    cout << endl;
    showMainMenu();
  }
}

void showMainMenu() {
  cout << "< HOSPITAL MANAGEMENT SYSTEM >" << endl;
  cout << "\t" << "01: Doctors" << endl;
  cout << "\t" << "02: Patients" << endl;
  cout << "\t" << "03: Appointments" << endl;
  cout << "\t" << "-1: Exit" << endl;

  int operationNumber;
  do {
    cout << "Enter section number: ";
    cin >> operationNumber;
    if (operationNumber > 3 || operationNumber < -1 || operationNumber == 0) {
      cout << "Invalid section number!" << endl;
    }
  } while (operationNumber > 3 || operationNumber < -1 || operationNumber == 0);
  cout << endl;
  if (operationNumber == 1) {
    showDoctorsMenu();
  } else if (operationNumber == 2) {
    showPatientsMenu();
  } else if (operationNumber == 3) {

  } else if (operationNumber == -1) {
    exit(0);
  }
}

int main() {


  return 0;
}