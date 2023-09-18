//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#ifndef OOP_HOSPITAL_DOCTOR_H_
#define OOP_HOSPITAL_DOCTOR_H_

#include "person.h"

class doctor : public person {
 private:
  string specialization;

 public:
  doctor();
  doctor(int _id, string _fName, string _lName, int _age, string _gender, string _phNumber, string _specialization);

  void printDetails();
};

#endif //OOP_HOSPITAL_DOCTOR_H_
