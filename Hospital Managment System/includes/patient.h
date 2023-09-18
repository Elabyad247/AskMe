//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#ifndef OOP_HOSPITAL_PATIENT_H_
#define OOP_HOSPITAL_PATIENT_H_

#include "person.h"

class patient : public person {
 private:
  string sickness;

 public:
  patient();
  patient(int _id, string _fName, string _lName, int _age, string _gender, string _phNumber, string _sickness);

  void setSickness(string newSickness);
  string getSickness();

  void printDetails();
};

#endif //OOP_HOSPITAL_PATIENT_H_
