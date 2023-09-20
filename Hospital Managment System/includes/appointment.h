//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#ifndef OOP_HOSPITAL_APPOINTMENT_H_
#define OOP_HOSPITAL_APPOINTMENT_H_

#include "Hospital.h"
#include "doctor.h"
#include "patient.h"

class appointment {
 private:
  int id;
  int hour;
  string date;
  doctor aDoctor;
  patient aPatient;
 public:
  appointment();

  void book();
  void getDetails();
  void printDetails();

  void loadData();
};

#endif //OOP_HOSPITAL_APPOINTMENT_H_
