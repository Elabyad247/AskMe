//
// Created by Saifaldin Elabyad on 18/09/2023.
//

#include "../includes/person.h"
#include <string>
#include <iostream>
using namespace std;

person::person() {
  id = -1;
  fName = "";
  lName = "";
  age = -1;
  gender = "";
  phNumber = "";
}

void person::addPerson() {
  cout << "Enter first name: ";
  cin >> fName;
  cout << "Enter last name: ";
  cin >> lName;
  cout << "Enter age: ";
  cin >> age;
  cout << "Enter gender: ";
  cin >> gender;
  cout << "Enter phone number: ";
  cin >> phNumber;
}

string person::getFullName() {
  string r = fName + " " + lName;
  return r;
}

void person::getDetails() {
  cout << "Details:" << endl;
  cout << "ID: " << id << endl;
  cout << "Full Name: " << getFullName() << endl;
  cout << "Age: " << age << endl;
  cout << "Gender: " << gender << endl;
  cout << "Phone Number: " << phNumber << endl;
}

void person::printDetails() {
  cout << "Details:" << endl;
  cout << "ID: " << id << endl;
  cout << "Full Name: " << getFullName() << endl;
  cout << "Age: " << age << endl;
  cout << "Gender: " << gender << endl;
  cout << "Phone Number: " << phNumber << endl;
}