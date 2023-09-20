//
// Created by Saifaldin Elabyad on 18/09/2023.
//
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "includes/person.h"
#include "includes/Hospital.h"
#include "includes/doctor.h"
#include "includes/patient.h"
using namespace std;

void loadData() {
  doctor doc;
  doc.loadData();
  patient pat;
  pat.loadData();
}

void showMainMenu();
void showDoctorsMenu();
void showPatientsMenu();
void showAppointmentsMenu();

void showAppointmentsMenu() {
  bool back = false;
  while (!back) {
    cout << "< APPOINTMENTS SECTION >" << endl;
    cout << "\t" << "01: Book Appointment" << endl;
    cout << "\t" << "02: Remove Appointment" << endl;
    cout << "\t" << "03: Get Appointment Details" << endl;
    cout << "\t" << "04: Show All Appointments" << endl;
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
      back = true;
    }
  }
}

void showPatientsMenu() {
  bool back = false;
  while (!back) {
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
      patient pat;
      pat.addPerson();
      cout << "Press Enter to go back";
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } else if (operationNumber == 2) {
      patient pat;
      pat.removePerson();
      cout << "Press Enter to go back";
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } else if (operationNumber == 3) {
      patient pat;
      pat.getDetails();
      cout << "Press Enter to go back";
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } else if (operationNumber == 4) {
      Hospital::printPatients();
      cout << "Press Enter to go back";
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } else if (operationNumber == -1) {
      cout << endl;
      back = true;
    }
  }
}

void showDoctorsMenu() {
  bool back = false;
  while (!back) {
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
      doctor doc;
      doc.addPerson();
      cout << "Press Enter to go back";
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } else if (operationNumber == 2) {
      doctor doc;
      doc.removePerson();
      cout << "Press Enter to go back";
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } else if (operationNumber == 3) {
      doctor doc;
      doc.getDetails();
      cout << "Press Enter to go back";
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } else if (operationNumber == 4) {
      Hospital::printDoctors();
      cout << "Press Enter to go back";
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } else if (operationNumber == -1) {
      cout << endl;
      back = true;
    }
  }
}

void showMainMenu() {
  while (true) {
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
      showAppointmentsMenu();
    } else if (operationNumber == -1) {
      exit(0);
    }
  }
}

int main() {
  loadData();
  showMainMenu();
  return 0;
}