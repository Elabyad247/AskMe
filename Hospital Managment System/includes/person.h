//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#ifndef OOP_HOSPITAL_PERSON_H_
#define OOP_HOSPITAL_PERSON_H_
#include <string>
using namespace std;

class person {
 protected:
  int id;
  string fName;
  string lName;
  int age;
  string gender;
  string phNumber;

 public:
  person();
  person(int _id, string _fName, string _lName, int _age, string _gender, string _phNumber);

};

#endif //OOP_HOSPITAL_PERSON_H_
