//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#ifndef OOP_HOSPITAL_HOSPITAL_H_
#define OOP_HOSPITAL_HOSPITAL_H_
#include <map>

#include "doctor.h"
#include "patient.h"
#include "appointment.h"

class Hospital {
 private:
  map<int, doctor> doctorsList;
  map<int, patient> patientsList;
  map<int, appointment> appointmentsList;

  friend class doctor;
  friend class patient;
  friend class appointment;
 public:

  void printDoctors();
  void printPatients();
  void printAppointments();
};

#endif //OOP_HOSPITAL_HOSPITAL_H_
