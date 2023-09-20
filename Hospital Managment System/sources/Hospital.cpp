//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#include "../includes/Hospital.h"
#include <iostream>

map<int, doctor> Hospital::doctorsList;
map<int, patient> Hospital::patientsList;

void Hospital::printDoctors() {
  cout << "< ALL DOCTORS DETAILS >" << endl;
  for (auto &doctor: doctorsList) {
    doctor.second.printDetails();
    cout << "=====================================================" << endl;
  }
}

void Hospital::printPatients() {
  cout << "< ALL PATIENTS DETAILS >" << endl;
  for (auto &patient: patientsList) {
    patient.second.printDetails();
    cout << "=====================================================" << endl;
  }
}