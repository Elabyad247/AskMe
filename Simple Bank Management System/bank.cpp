//
// Created by Saifaldin Elabyad on 27/08/2023.
//

#include "bank.h"

customer::customer() : uID(0), uName("Unknown"), uPhone("Unknown"), uAddress("Unknown"), uAccountNumber(0) {}
customer::customer(int id, string name, string phone, string address, int accountNumber) {
  uID = id;
  uName = name;
  uPhone = phone;
  uAddress = address;
  uAccountNumber = accountNumber;
  customerCounter++;
}
int customer::getID() const {
  return uID;
}
string customer::getName() const {
  return uName;
}
string customer::getPhone() const {
  return uPhone;
}
string customer::getAddress() const {
  return uAddress;
}
int customer::getAccountNumber() const {
  return uAccountNumber;
}
void customer::setAccountNumber(int accountNumber) {
  uAccountNumber = accountNumber;
}


account::account() : aID(0), cID(0), aNumber(0), aBalance(0), aType("Unknown") {}
account::account(int id, int customerID, int number, int balance, string type) {
  aID = id;
  cID = customerID;
  aNumber = number;
  aBalance = balance;
  aType = type;
  accountCounter++;
}
int account::getID() const {
  return aID;
}
int account::getCustomerID() const {
  return cID;
}
int account::getAccountNumber() const {
  return aNumber;
}
int account::getBalance() const {
  return aBalance;
}
string account::getType() const {
  return aType;
}
void account::deposit(int amount) {
  aBalance += amount;
  cout << "\t" << "You have deposited $" << amount << " and the current balance is " << aBalance << endl;
}
void account::withdraw(int amount) {
  if (amount <= aBalance) {
    aBalance -= amount;
    cout << "\t" << "You have withdrawn $" << amount << " and the remaining is " << aBalance << endl;
  } else {
    cout << "\t" << "You don't have enough balance in your account!" << endl;
  }
}