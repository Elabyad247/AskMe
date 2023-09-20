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
  static map<int, doctor> doctorsList;
  static map<int, patient> patientsList;
  static map<int, appointment> appointmentsList;

  friend class doctor;
  friend class patient;
  friend class appointment;
 public:

  static void printDoctors();
  static void printPatients();
  static void printAppointments();
};

#endif //OOP_HOSPITAL_HOSPITAL_H_
