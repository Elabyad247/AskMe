//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#ifndef OOP_HOSPITAL_DOCTOR_H_
#define OOP_HOSPITAL_DOCTOR_H_

#include "person.h"

class appointment;
class doctor : public person {
 private:
  string specialization;
  friend class appointment;

 public:
  doctor();

  void getDetails();
  void printDetails();
  void addPerson();
  void removePerson();
  void loadData();
};

#endif //OOP_HOSPITAL_DOCTOR_H_
