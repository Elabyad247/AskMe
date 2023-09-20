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

  virtual void getDetails();
  virtual void printDetails();
  virtual void addPerson();
  virtual void removePerson() = 0;
  virtual void loadData() = 0;
  string getFullName();
};

#endif //OOP_HOSPITAL_PERSON_H_
