//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#ifndef OOP_HOSPITAL_PATIENT_H_
#define OOP_HOSPITAL_PATIENT_H_

#include "person.h"
#include <string>
using namespace std;

class appointment;
class patient : public person {
 private:
  string sickness;
  friend class appointment;

 public:
  patient();

  void getDetails();
  void printDetails();
  void addPerson();
  void removePerson();
  void loadData();
  string getSickness();
};

#endif //OOP_HOSPITAL_PATIENT_H_
