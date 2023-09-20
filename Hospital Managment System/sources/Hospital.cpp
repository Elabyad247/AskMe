//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#include "../includes/Hospital.h"
#include <iostream>
#include <sstream>

map<int, doctor> Hospital::doctorsList;
map<int, patient> Hospital::patientsList;
map<int, appointment> Hospital::appointmentsList;

static int ToInt(const string &str) {
  istringstream iss(str);
  int num;
  iss >> num;
  return num;
}

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

void Hospital::printAppointments() {
  cout << "< ALL APPOINTMENTS DETAILS >" << endl;
  for (auto &appointment: appointmentsList) {
    appointment.second.printDetails();
    cout << "=====================================================" << endl;
  }
}