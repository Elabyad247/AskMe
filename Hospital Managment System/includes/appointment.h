//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#ifndef OOP_HOSPITAL_APPOINTMENT_H_
#define OOP_HOSPITAL_APPOINTMENT_H_

#include "doctor.h"
#include "patient.h"

class appointment {
 private:
  int id;
  string date;
  doctor aDoctor;
 public:
  appointment();

  void printDetails();
};

#endif //OOP_HOSPITAL_APPOINTMENT_H_
